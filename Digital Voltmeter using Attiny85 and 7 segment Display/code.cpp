// C++ Arduino-style code for ATtiny85-based voltmeter

const int analogPin = A1; // Analog input from voltage divider/potentiometer

// Segment pins for 7-segment (a to g)
const int segmentPins[7] = {0, 1, 2, 3, 4, 5, 6}; // Adjust based on ATtiny85 wiring
// Digit select pins (common cathode control)
const int digitPins[4] = {7, 8, 9, 10}; // You might use shift registers instead (e.g., 74HC595)

// 7-segment code for digits 0-9 (a-g segments) — common cathode
const uint8_t digits[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH); // Disable all digits initially
  }
}

void loop() {
  int sensorValue = analogRead(analogPin); // Read analog input (0-1023)
  float voltage = (sensorValue * 5.0) / 1023.0; // Convert to voltage (0-5V)
  int displayValue = voltage * 100; // Scale to 0–500 for 2 decimal digits

  displayVoltage(displayValue);
}

// Display function for 4-digit 7-segment display
void displayVoltage(int value) {
  int digit[4];
  digit[0] = value / 1000;
  digit[1] = (value / 100) % 10;
  digit[2] = (value / 10) % 10;
  digit[3] = value % 10;

  for (int i = 0; i < 4; i++) {
    showDigit(digit[i], i);
    delay(3); // Multiplex delay
    clearDigits();
  }
}

// Show a single digit
void showDigit(int number, int position) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(digits[number], i));
  }
  digitalWrite(digitPins[position], LOW); // Enable the current digit
}

// Turn off all digits
void clearDigits() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], HIGH); // Disable all digits
  }
}

