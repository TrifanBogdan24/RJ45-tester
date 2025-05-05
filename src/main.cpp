#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address (most common are 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(); // Use default pins: SDA=GP0, SCL=GP1

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello");


  pinMode(25, OUTPUT);
}

void loop() {
  // Nothing here
  digitalWrite(25, HIGH);
  delay(300);
  digitalWrite(25, LOW);
  delay(300);
}
