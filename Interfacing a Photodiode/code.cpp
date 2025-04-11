int sensorPin = A0;  // Pin connected to the photodiode
int sensorValue = 0;

void setup() {
  Serial.begin(9600);       // Start serial monitor
  pinMode(sensorPin, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);  // Read analog value from photodiode
  Serial.println(sensorValue);          // Print value to Serial Monitor
  delay(500);                           // Delay for readability
}

