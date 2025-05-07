#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define CABLE_TYPE_CROSSOVER        (bool) 0
#define CABLE_TYPE_STRAIGHT_THROUGH (bool) 1

// Set the LCD address
LiquidCrystal_I2C lcd(0x27, 16, 2);


// 0 = Straight-through ; 1 = Crossover
volatile bool cableType = false;
volatile bool updatedBTN1 = false;   // Blue button (switch cable type)
volatile bool updatedBTN2 = false;   // Red button (force stop)
volatile bool updatedBTN3 = false;   // White button (start tester)

// Pentru intreruperile pe PCINT
volatile uint8_t lastPortD = 0;



bool pinsSenderSocket[8];



// Intrerupere pe pinul D2 (BTN1)
ISR(INT0_vect) {
    if (updatedBTN1) return;
    cableType = !cableType;
    updatedBTN1 = true;
}


// Intrerupere pe pinul D3 (BTN2)
ISR(INT1_vect) {
    if (updatedBTN2) return;
    updatedBTN2 = true;
}



ISR(PCINT2_vect) {
    uint8_t current = PIND;
    uint8_t changed = current ^ lastPortD;

    if (changed & (1 << PD4)) {
        updatedBTN3 = true;
    }

    lastPortD = current;
}


/*
* Functia se va folosi cand semnalul ajunge la sender pe un pin gresit, sau nu ajunge deloc
*/
void long_beep()
{
    for (int i = 0; i < 250; i++) {
        // Pentru a mari frecventa, micsoreaza delay-ul
        PORTD |= (1 << PD5);   // HIGH
        delayMicroseconds(1000);
        PORTD &= ~(1 << PD5);  // LOW
        delayMicroseconds(1000);
    }
}


/*
* Functia se va folosi cand semnalul ajunge la sender pe pinul corect
*/
void short_beep()
{
    for (int i = 0; i < 400; i++) {
        // Pentru a mari frecventa, micsoreaza delay-ul
        PORTD |= (1 << PD5);   // HIGH
        delayMicroseconds(200);
        PORTD &= ~(1 << PD5);  // LOW
        delayMicroseconds(200);
    }
}

void cable_type_first_line_lcd()
{
    lcd.setCursor(0, 0);
    if (cableType == CABLE_TYPE_STRAIGHT_THROUGH) {
        lcd.print("Straight-through");
    } else {
        lcd.print("Cross-over      ");
    }  
}


void cable_mode_full_lcd()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mode:");
    lcd.setCursor(0, 1);

    if (cableType == CABLE_TYPE_STRAIGHT_THROUGH) {
        lcd.print("Straight-through");
    } else {
        lcd.print("Cross-over");
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
            // LOW pe D6 (register data)
            PORTD |= (1 << PD6);
        } else {
            // HIGH pe D6 (register data)
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
    Serial.begin(9600);

    cableType = false;

    lcd.begin(16, 2);
    lcd.backlight();

    cable_mode_full_lcd();


    
    // Input pins: D1 (for BTN1), D2 (for BTN2), D3 (for BTN3)
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4));
    PORTD |= (1 << PD2) | (1 << PD3) | (1 << PD4); 


    // Output pin for BUZZER: D5
    DDRD |= (1 << PD5);

    // Output pins pe Arduino pt shift register-ul asociat sender-ului:
    DDRD |= (1 << PD6);   // pin D6 -> register data
    DDRD |= (1 << PD7);   // pin D7 -> register latch
    DDRB |= (1 << PB0);   // pin D8 -> register clock

    init_sender_pins();

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
}



void force_stop_handler()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Force stop!");
    delay(2000);
    cable_mode_full_lcd();
}


void test_individual_rj45_pins()
{
    for (int i = 0; i < 8; i++) {
        pinsSenderSocket[i] = true;
        write_to_sender_socket();

        lcd.setCursor(13, 1);
        lcd.print(i + 1);

        // 1s pause betweem testing another RJ45 pin
        for (int j = 0; j < 10; j++) {
            if (updatedBTN2) {
                force_stop_handler();
                return;
            }
            delay(100);
        }

        pinsSenderSocket[i] = false;
        write_to_sender_socket();
        delay(500);
        if (updatedBTN2) {
            force_stop_handler();
            return;
        }
    }


    init_sender_pins();
    cable_type_first_line_lcd();
    lcd.setCursor(0, 1);
    lcd.print("Done            ");
    delay(2000);
    cable_mode_full_lcd();
}

void test_all_rj45_pins()
{
    // TODO:
}

void loop() {
    if (updatedBTN1) {
        cable_mode_full_lcd();
    }


    if (updatedBTN3) {
        lcd.clear();
        cable_type_first_line_lcd();

        lcd.setCursor(0, 1);
        lcd.print("Testing pin: ");

        test_individual_rj45_pins();
    }


    updatedBTN1 = false;
    updatedBTN2 = false;
    updatedBTN3 = false;
    delay(200);
}
