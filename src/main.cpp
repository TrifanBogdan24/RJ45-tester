#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <SD.h>
#include "main_display.h"


#define CABLE_TYPE_STRAIGHT_THROUGH (int) 0
#define CABLE_TYPE_CROSSOVER        (int) 1
#define CABLE_TYPE_ROLLOVER         (int) 2

// Pini rezervati pe Arduino pt modul MicroSD:
#define PIN_MICRO_SD_MODULE_CS (int) 9   // Chip Select -> D9


// Pini rezervati pe Arduino pt display-ul pe SPI (128x160):
#define PIN_IMAGE_DIPSLAY_CS (int) 10  // Chip Select -> D10
#define PIN_IMAGE_DISPLAY_RS (int) 14  // Register Select -> A0 (D14)



LiquidCrystal_I2C i2c_lcd(0x27, 16, 2);


// 0 = Straight-through ; 1 = Crossover ; 2 = Rollover
volatile int cableType = CABLE_TYPE_STRAIGHT_THROUGH;

volatile bool pressedBTN1 = false;   // Blue button (switch cable type)
volatile bool pressedBTN2 = false;   // Red button (force stop)
volatile bool pressedBTN3 = false;   // White button (start tester)

bool isRunningTest = false;

// Pentru intreruperile pe PCINT
volatile uint8_t lastPortD = 0;


const int dataPin = A1;  // QH (serial out)
const int plPin   = A2;  // /PL (parallel load)
const int clkPin  = A3;  // CP (clock)

// Vector de stocare a bitilor
bool pinsReceiverSocket[8];
bool pinsSenderSocket[8];



// Intrerupere pe pinul D2 (BTN1)
ISR(INT0_vect) {
    if (isRunningTest || pressedBTN1) return;
    cableType = (cableType + 1) % 3;
    pressedBTN1 = true;
}


// Intrerupere pe pinul D3 (BTN2)
ISR(INT1_vect) {
    if (pressedBTN2) return;
    pressedBTN2 = true;
}



ISR(PCINT2_vect) {
    uint8_t current = PIND;
    uint8_t changed = current ^ lastPortD;

    if (changed & (1 << PD4)) {
        pressedBTN3 = true;
    }

    lastPortD = current;
}


/*
* Functia se va folosi cand semnalul ajunge la sender pe un pin gresit, sau nu ajunge deloc
*/
void beep_not_okay()
{
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 250; i++) {
            // Pentru a mari frecventa, micsoreaza delay-ul
            PORTD |= (1 << PD5);   // HIGH
            delayMicroseconds(1000);
            PORTD &= ~(1 << PD5);  // LOW
            delayMicroseconds(1000);
        }

        if (j < 1) delay(50);
    }

}


/*
* Functia se va folosi cand semnalul ajunge la sender pe pinul corect
*/
void beep_okay()
{
    for (int i = 0; i < 400; i++) {
        // Pentru a mari frecventa, micsoreaza delay-ul
        PORTD |= (1 << PD5);   // HIGH
        delayMicroseconds(200);   // frecventa inalta
        PORTD &= ~(1 << PD5);  // LOW
        delayMicroseconds(200);
    }
}

void write_cable_type_on_first_line_of_i2c_lcd()
{
    i2c_lcd.setCursor(0, 0);
    if (cableType == CABLE_TYPE_STRAIGHT_THROUGH) {
        i2c_lcd.print("Straight-through");
    } else if (cableType == CABLE_TYPE_CROSSOVER) {
        i2c_lcd.print("Crossover      ");
    } else if (cableType == CABLE_TYPE_ROLLOVER) {
        i2c_lcd.print("Rollover        ");
    }
}


void write_full_cable_mode_on_i2c_lcd()
{
    i2c_lcd.clear();
    i2c_lcd.setCursor(0, 0);
    i2c_lcd.print("Mode:");
    i2c_lcd.setCursor(0, 1);

    if (cableType == CABLE_TYPE_STRAIGHT_THROUGH) {
        i2c_lcd.print("Straight-through");
    } else if (cableType == CABLE_TYPE_CROSSOVER) {
        i2c_lcd.print("Crossover      ");
    } else if (cableType == CABLE_TYPE_ROLLOVER) {
        i2c_lcd.print("Rollover        ");
    }
}



/*
* ATENTIE: modificarea unei singure valori presupune
* scrierea tuturor celorlalte pe shift register (pt a pastra starea lor)
*/
void write_to_sender_socket()
{
    // LOW pe pinul D7 -> register latch
    PORTD |= (1 << PD7);
  
    // Trimite in ordine inversa, deoarece shift-registrul foloseste LSB first
    for (int i = 7; i >= 0; i--) {
        if (pinsSenderSocket[i]) {
            // HIGH pe D6 (register data)
            PORTD |= (1 << PD6);
        } else {
            // LOW pe D6 (register data)
            PORTD &= ~(1 << PD6);
        }
  

        // Creez un front de ceas (rising + falling edge):
       PORTB &= ~(1 << PB0);  // HIGH pe D8 (register clock)
       PORTB |= (1 << PB0);   // LOW pe D8 (register clock)
    }
  
    // HIGH pe pinul D7 -> register latch
    PORTD &= ~(1 << PD7);
}


void init_sender_pins()
{
    for (int i = 0; i < 8; i++) {
        pinsSenderSocket[i] = false;
    }
    write_to_sender_socket();
}





void setup() {
    // Output pins pe Arduino pt shift register-ul 74HC595 (asociat sender-ului):
    DDRD |= (1 << PD6);   // pin D6 -> register data
    DDRD |= (1 << PD7);   // pin D7 -> register latch
    DDRB |= (1 << PB0);   // pin D8 -> register clock
    init_sender_pins();


    // Configurare pini pt shift register-ul 74HC165 (asociat receiver-ului):
    DDRC &= ~(1 << PC0);   // input pin D14 -> register QH (serial out)
    DDRC |= (1 << PC1);    // output pin D15 -> register !PL (parallel load)
    DDRC |= (1 << PC2);    // output pin D16 -> register CP (clock) 
    for (int i = 0; i < 8; i++) {
        pinsReceiverSocket[i] = false;
    }


    // Stare inițială a shift register-ului asociat receiver-ului
    PORTC |= (1 << PC1);  // LOW pe pin D15 (register parallel load)
    PORTC &= ~(1 << PC2);  // LOW pe pin D16 (register clock)


    cableType = CABLE_TYPE_STRAIGHT_THROUGH;

    i2c_lcd.begin(16, 2);
    i2c_lcd.backlight();

    write_full_cable_mode_on_i2c_lcd();


    // Input pins: D1 (for BTN1), D2 (for BTN2), D3 (for BTN3)
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4));
    PORTD |= (1 << PD2) | (1 << PD3) | (1 << PD4); 


    // Output pin for BUZZER: D5
    DDRD |= (1 << PD5);


    // Config intreperi pt INT0 (pe BTN1) si INT1 (pe BTN2)
    EICRA |= ((1 << ISC01) | (1 << ISC11));
    EICRA &= ~((1 << ISC00) | (1 << ISC10));
    // Permite intrerupere pe INT0 și INT1
    EIMSK |= (1 << INT0) | (1 << INT1);
    // Sterge flag-urile anterioare pe INT0 si INT1
    EIFR |= (1 << INTF0) | (1 << INTF1);


    // Config intreupere pin change pe D4 (pt BTN3)
    PCICR |= (1 << PCIE2);
    // Permite intrerupere pe PCINT20
    PCMSK2 |= (1 << PCINT20); 
    // Sterge flag-urile anterioare
    PCIFR |= (1 << PCIF2);


    // Activeaza intreruperile
    sei();

    // It's better to double-check
    init_sender_pins();

    while (!SD.begin(PIN_MICRO_SD_MODULE_CS)) {
        // "[ERR] SD init failed!");
        delay(200);
    }
    // "[OK] SD init success!");

    int is_micro_sd_err = 0;
    do {
        is_micro_sd_err = 0;

        if (SD.exists("cross.bmp")) {
            // "[OK] 'cross.bmp'");
        } else {
            // "[ERR] No such file 'cross.bmp' on microSD!");
            is_micro_sd_err = 1;
        }

        if (SD.exists("straight.bmp")) {
            // "[OK] 'straight.bmp'");
        } else {
            // "[ERR] No such file 'straight.bmp' on microSD!");
            is_micro_sd_err = 1;
        }

        delay(200);
    } while (is_micro_sd_err);

    // MicroSD is ready to go


    draw_straight_through_wiring();
}



void force_stop_handler()
{
    i2c_lcd.clear();
    i2c_lcd.setCursor(0, 0);
    i2c_lcd.print("Force stop!");
    init_sender_pins();
    delay(2000);
    write_full_cable_mode_on_i2c_lcd();
}

void fetch_receiver_socket()
{
    PORTC &= ~(1 << PC1);  // LOW pe pin D15 (register parallel load)
    delayMicroseconds(5);
    PORTC |= (1 << PC1);  // HIGH pe pin D15 (register parallel load)

    // 2. Citește fiecare bit
    for (int i = 0; i < 8; i++) {
        // Shift register-ul transmite serial valorile,
        // incepand cu bitul D7 -> D6 -> ... -> D0 prin pinul QH
        // Se foloseste ordinea MSB -> trebuie inversata din cod
        pinsReceiverSocket[7 - i] = PINC & (1 << PC0);   // read pin D14 (register serial out)

        // Pulseaza ceasul
        PORTC |= (1 << PC2);  // HIGH pe pin D16 (register clock)
        delayMicroseconds(5);
        PORTC &= ~(1 << PC2);  // LOW pe pin D16 (register clock)
        delayMicroseconds(5);
    }
}


bool is_correct_wiring(int pin_index)
{
    fetch_receiver_socket();

    if (cableType == CABLE_TYPE_CROSSOVER) {
        if (pin_index == 0) return pinsReceiverSocket[2];
        else if (pin_index == 1) return pinsReceiverSocket[5];
        else if (pin_index == 2) return pinsReceiverSocket[0];
        else if (pin_index == 3) return pinsReceiverSocket[2];
        else if (pin_index == 4) return pinsReceiverSocket[3];
        else if (pin_index == 5) return pinsReceiverSocket[1];
        else if (pin_index == 6) return pinsReceiverSocket[6];
        else if (pin_index == 7) return pinsReceiverSocket[7];
    }

    if (cableType == CABLE_TYPE_STRAIGHT_THROUGH) {
        return pinsReceiverSocket[pin_index];
    }


    if (cableType == CABLE_TYPE_ROLLOVER) {
        return pinsReceiverSocket[7 - pin_index];
    }


    // unknown cableType
    return false;
}


void test_individual_rj45_pins()
{
    i2c_lcd.setCursor(0, 1);
    i2c_lcd.print("SND ");   // writes 4 chars
    i2c_lcd.setCursor(5, 1);
    i2c_lcd.print("->RCV "); // writes 6 chars



    for (int i = 0; i < 8; i++) {
        pinsSenderSocket[i] = true;
        write_to_sender_socket();
        if (pressedBTN2) {
            force_stop_handler();
            return;
        }


        // Scrie indicele pinului pt SENDER
        i2c_lcd.setCursor(4, 1);
        i2c_lcd.print(i + 1);        // writes 1 digit
        i2c_lcd.setCursor(13, 1);
        i2c_lcd.print("   ");

        // Scrie indiciele pinului pe care RECEIVER ar trb in mod normal sa primeasca semnal
        i2c_lcd.setCursor(11, 1);
        if (cableType == CABLE_TYPE_CROSSOVER) {
            // writes 1 digit
            if (i == 0) i2c_lcd.print(3);
            else if (i == 1) i2c_lcd.print(6);
            else if (i == 2) i2c_lcd.print(1);
            else if (i == 3) i2c_lcd.print(4);
            else if (i == 4) i2c_lcd.print(5);
            else if (i == 5) i2c_lcd.print(2);
            else if (i == 6) i2c_lcd.print(7);
            else if (i == 7) i2c_lcd.print(8);
        } else if (cableType == CABLE_TYPE_STRAIGHT_THROUGH) {
            i2c_lcd.print(i + 1);        // writes 1 digit
        } else if (cableType == CABLE_TYPE_ROLLOVER) {
            i2c_lcd.print(8 - i);       // writes 1 digit
        }



        // 1s pause betweem testing another RJ45 pin
        for (int j = 0; j < 10; j++) {
            if (pressedBTN2) {
                force_stop_handler();
                return;
            }
            delay(100);
        }

        pinsSenderSocket[i] = false;
        write_to_sender_socket();
        if (pressedBTN2) {
            force_stop_handler();
            return;
        }
        
        delay(20);  // un mic delay pt a astepta semnalul pe cablu
        if (is_correct_wiring(i)) {
            i2c_lcd.setCursor(13, 1);
            i2c_lcd.print(" OK");
            beep_okay();
            delay(340);
        } else {
            i2c_lcd.setCursor(13, 1);
            i2c_lcd.print("NOK");
            beep_not_okay();
        }
  
        if (pressedBTN2) {
            force_stop_handler();
            return;
        }

        delay(500);
        if (pressedBTN2) {
            force_stop_handler();
            return;
        }

    }


    init_sender_pins();
    write_cable_type_on_first_line_of_i2c_lcd();
    i2c_lcd.setCursor(0, 1);
    i2c_lcd.print("Done            ");
    delay(2000);
    write_full_cable_mode_on_i2c_lcd();
}

void test_all_rj45_pins()
{
    // TODO:
}



void loop() {
    if (pressedBTN1) {
        write_full_cable_mode_on_i2c_lcd();
        if (cableType == CABLE_TYPE_STRAIGHT_THROUGH) draw_straight_through_wiring();
        else if (cableType == CABLE_TYPE_CROSSOVER) draw_crossover_wiring();
        else if (cableType == CABLE_TYPE_ROLLOVER) draw_rollover_wiring();
    }


    if (pressedBTN3) {
        isRunningTest = true;
        i2c_lcd.clear();
        write_cable_type_on_first_line_of_i2c_lcd();

        i2c_lcd.setCursor(0, 1);
        i2c_lcd.print("Testing pin: ");

        test_individual_rj45_pins();
        init_sender_pins();
        isRunningTest = false;
    }

    pressedBTN1 = false;
    pressedBTN2 = false;
    pressedBTN3 = false;

    delay(200);
}
