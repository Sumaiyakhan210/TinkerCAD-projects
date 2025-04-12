int potPin = A0;        // Potentiometer connected to A0
int ledPin = 9;         // LED connected to digital pin 9
int potValue = 0;       
int brightness = 0;     

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  potValue = analogRead(potPin);            // Read value from potentiometer (0–1023)
  brightness = map(potValue, 0, 1023, 0, 255); // Convert to PWM range
  analogWrite(ledPin, brightness);          // Write PWM signal to LED
  delay(10);
}
