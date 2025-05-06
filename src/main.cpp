#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address
LiquidCrystal_I2C lcd(0x27, 16, 2);


// 0 = Straight-through ; 1 = Crossover
volatile bool cableType = false;
volatile bool updatedBTN1 = false;

ISR(INT0_vect) {
    if (updatedBTN1) return;
    cableType = !cableType;
    updatedBTN1 = true;
}

/*
* Functia se va folosi cand semnalul ajunge la sender pe un pin gresit, sau nu ajunge deloc
*/
void long_beep()
{
    for (int i = 0; i < 200; i++) {
        // Pentru a mari frecventa, micsoreaza delay-ul
        PORTD |= (1 << PD5);   // HIGH
        delayMicroseconds(800);
        PORTD &= ~(1 << PD5);  // LOW
        delayMicroseconds(800);
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

void setup() {
    Serial.begin(9600);

    cableType = false;

    lcd.begin(16, 2);
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Mode:");
    lcd.setCursor(0, 1);
    lcd.print("Straight-through");


    
    // D2 - pin de intrare (BTN1)
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    // Intrerupere atasata pinului D2 (BTN1)
    EICRA |= (1 << ISC01);
    EICRA &= ~(1 << ISC00);
    EIMSK |= (1 << INT0);
    EIFR |= (1 << INTF0);

    // D5 - pin de iesire (BUZZER)
    DDRD |= (1 << PD5);

    // Activeaza intreruperile
    sei();


    // Testing:
    for (int i = 0; i < 8; i++) {
        short_beep();
        delay(300);
    }
    long_beep();
    delay(300);


}

void loop() {
    if (updatedBTN1) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Mode:");
        lcd.setCursor(0, 1);

        if (!cableType) {
            lcd.print("Straight-through");
        } else {
            lcd.print("Cross-over");
        }
    }




    updatedBTN1 = false;
    delay(200);
}
