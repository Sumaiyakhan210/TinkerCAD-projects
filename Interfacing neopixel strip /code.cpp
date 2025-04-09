// Pin Definitions
const int redPin = 9;   // Red LED pin
const int greenPin = 10; // Green LED pin
const int bluePin = 11;  // Blue LED pin

void setup() {
  // Set the LED pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Example: Cycle through different colors
  // Red
  analogWrite(redPin, 255);    // Full intensity of Red
  analogWrite(greenPin, 0);    // No Green
  analogWrite(bluePin, 0);     // No Blue
  delay(1000); // Wait for 1 second

  // Green
  analogWrite(redPin, 0);     // No Red
  analogWrite(greenPin, 255); // Full intensity of Green
  analogWrite(bluePin, 0);    // No Blue
  delay(1000); // Wait for 1 second

  // Blue
  analogWrite(redPin, 0);     // No Red
  analogWrite(greenPin, 0);   // No Green
  analogWrite(bluePin, 255);  // Full intensity of Blue
  delay(1000); // Wait for 1 second
}

