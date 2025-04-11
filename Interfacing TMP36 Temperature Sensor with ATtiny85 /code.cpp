// Define LED pins
int redPin = 0;     // PB0
int greenPin = 1;   // PB1
int bluePin = 2;    // PB2

// TMP36 analog pin
int tempPin = A2;   // PB4

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int analogValue = analogRead(tempPin);
  float voltage = analogValue * (5.0 / 1024.0);
  float temperature = (voltage - 0.5) * 100.0;

  // Control LEDs based on temperature
  if (temperature > 10) {
    digitalWrite(redPin, HIGH);
  } else {
    digitalWrite(redPin, LOW);
  }

  if (temperature > 15) {
    digitalWrite(greenPin, HIGH);
  } else {
    digitalWrite(greenPin, LOW);
  }

  if (temperature > 20) {
    digitalWrite(bluePin, HIGH);
  } else {
    digitalWrite(bluePin, LOW);
  }

  delay(500);
}

