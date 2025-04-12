// Define pin numbers
const int pirPin = 2;     // PIR sensor input pin
const int ledPin = 13;    // LED output pin (built-in on most Arduino boards)

void setup() {
  pinMode(pirPin, INPUT);     // PIR sensor as input
  pinMode(ledPin, OUTPUT);    // LED as output
  Serial.begin(9600);         // Start serial communication
}

void loop() {
  int motionState = digitalRead(pirPin);  // Read PIR sensor state

  if (motionState == HIGH) {
    digitalWrite(ledPin, HIGH);           // Turn on LED
    Serial.println("Motion Detected!");
  } else {
    digitalWrite(ledPin, LOW);            // Turn off LED
    Serial.println("No Motion.");
  }

  delay(500);  // Small delay to reduce serial output spam
}
