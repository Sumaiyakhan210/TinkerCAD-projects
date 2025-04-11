// Pin Definitions
const int tempPin = A0;      // TMP36 sensor output connected to analog pin A0
const int redLED = 2;
const int greenLED = 3;
const int blueLED = 4;
const int whiteLED = 5;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tempPin);
  float voltage = sensorValue * (5.0 / 1023.0);     // Convert ADC to voltage
  float temperatureC = (voltage - 0.5) * 100;       // Convert voltage to temperature

  // Debug print
  Serial.print("Temperature: ");
  Serial.println(temperatureC);

  // LED Indicator Logic
  if (temperatureC < 10) {
    blinkLED(blueLED);
  } else if (temperatureC >= 10 && temperatureC < 15) {
    blinkLED(greenLED);
  } else if (temperatureC >= 15 && temperatureC < 20) {
    blinkLED(whiteLED);
  } else {
    blinkLED(redLED);
  }

  delay(1000); // Wait before next reading
}

void blinkLED(int ledPin) {
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(whiteLED, LOW);
  
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
}
