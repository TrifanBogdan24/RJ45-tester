#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address (most common are 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);


// 0 = Straight-through ; 1 = Crossover
volatile int cableType = 0;

void setup() {
    Serial.begin(9600);

    cableType = 0;

    lcd.begin(16, 2);
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Mode:");
    lcd.setCursor(0, 1);
    lcd.print("Straight-through");

    // D2 - pin de iesire
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);
}

void loop() {
    if (!(PIND & (1 << PD2))) {
        // Daca butonul conectat la D2 a fost apasat:
        cableType = !cableType;

        if (!cableType) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Mode:");
            lcd.setCursor(0, 1);
            lcd.print("Straight-through");
        } else {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Mode:");
            lcd.setCursor(0, 1);
            lcd.print("Cross-over");
        }

        while (!(PIND & (1 << PD2))) {}
    }
    delay(200);
}