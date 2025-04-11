const int ledPin = 0;      // PB0
const int tempPin = A1;    // PB2

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int analogValue = analogRead(tempPin);
  float voltage = analogValue * (5.0 / 1024.0);        // Convert analog to voltage
  float temperatureC = (voltage - 0.5) * 100.0;         // TMP36 formula
  float temperatureF = temperatureC * 1.8 + 32;         // Optional: Convert to Fahrenheit

  // Temperature ranges and blinking logic
  if (temperatureC < 0) {
    blinkLED(100);      // Very fast
  } else if (temperatureC >= 30 && temperatureC <= 50) {
    blinkLED(500);      // Normal
  } else if (temperatureC >= 80 && temperatureC <= 95) {
    blinkLED(1000);     // Slow
  } else if (temperatureC >= 100) {
    digitalWrite(ledPin, HIGH); // LED stays ON (fever warning)
  } else {
    digitalWrite(ledPin, LOW); // Otherwise, turn OFF
  }
}

void blinkLED(int delayTime) {
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}
