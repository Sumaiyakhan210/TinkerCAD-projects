#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0;  // TMP36 is connected to A0

void setup() {
  lcd.begin(16, 2);  // Set up the LCD's number of columns and rows
  lcd.print("Today's Temp:");
}

void loop() {
  int reading = analogRead(tempPin);  // Read analog value from sensor
  float voltage = reading * 5.0 / 1024.0;  // Convert to voltage (0–5V)
  float tempC = (voltage - 0.5) * 100.0;   // Convert to Celsius
  float tempF = (tempC * 9.0 / 5.0) + 32.0;  // Convert to Fahrenheit

  lcd.setCursor(0, 1);  // Set cursor to the second line
  lcd.print("C: ");
  lcd.print(tempC);
  lcd.print(" F: ");
  lcd.print(tempF);

  delay(1000);  // Wait 1 second before next read
}

