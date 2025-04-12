#include <Servo.h>
#include <LiquidCrystal.h>

// Servo and LCD setup
Servo gateServo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// IR sensor pins
int entrySensor = 7;
int exitSensor = 6;

// Variables
int totalSlots = 5;
int availableSlots = 5;

void setup() {
  gateServo.attach(9);  // Servo on pin 9
  pinMode(entrySensor, INPUT);
  pinMode(exitSensor, INPUT);
  
  lcd.begin(16, 2);
  lcd.print("Smart Parking");
  delay(2000);
  lcd.clear();
  updateDisplay();
}

void loop() {
  if (digitalRead(entrySensor) == LOW && availableSlots > 0) {
    gateServo.write(90);  // Open gate
    delay(1000);
    gateServo.write(0);   // Close gate
    availableSlots--;
    updateDisplay();
    delay(1000);
  }

  if (digitalRead(exitSensor) == LOW && availableSlots < totalSlots) {
    gateServo.write(90);
    delay(1000);
    gateServo.write(0);
    availableSlots++;
    updateDisplay();
    delay(1000);
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Available Slots:");
  lcd.setCursor(0, 1);
  lcd.print(availableSlots);
}
