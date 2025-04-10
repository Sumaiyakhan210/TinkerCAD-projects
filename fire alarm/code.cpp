

// Define pins
const int tempSensor = A1;
const int gasSensor = A0;
const int ledPin = 13;
const int piezoPin = 7;

void setup() {
  pinMode(tempSensor, INPUT);
  pinMode(gasSensor, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int vout = analogRead(tempSensor);
  int vout1 = analogRead(gasSensor);

  // Convert temperature value
  float temp = (vout * 5.0 * 100.0) / 1024.0;

  // Print values to serial monitor
  Serial.print("Temperature (°C): ");
  Serial.print(temp);
  Serial.print(" | Gas Value: ");
  Serial.println(vout1);

  // Temperature alert
  if (temp >= 80) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Gas alert
  if (vout1 >= 100) {
    digitalWrite(piezoPin, HIGH);
  } else {
    digitalWrite(piezoPin, LOW);
  }

  delay(1000); // Wait for 1 second
}
