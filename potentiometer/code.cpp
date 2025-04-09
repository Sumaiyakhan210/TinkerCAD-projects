// Pin definitions
int potPin = A0;     // Middle pin of potentiometer
int ledPin = 9;      // PWM pin connected to LED

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);         // Read analog value (0–1023)
  int brightness = map(potValue, 0, 1023, 0, 255);  // Map to PWM range (0–255)

  analogWrite(ledPin, brightness);           // Set LED brightness
  Serial.println(brightness);                // Debug output

  delay(50);  // Small delay
}
