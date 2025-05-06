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

void setup() {
    Serial.begin(9600);

    cableType = false;

    lcd.begin(16, 2);
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Mode:");
    lcd.setCursor(0, 1);
    lcd.print("Straight-through");

    // D2 - pin de iesire (legat catre BTN1)
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    // Intrerupere atasata pinului D2 (BTN1)
    EICRA |= (1 << ISC01);
    EICRA &= ~(1 << ISC00);
    EIMSK |= (1 << INT0);
    EIFR |= (1 << INTF0);

    sei();
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
