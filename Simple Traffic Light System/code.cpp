int red = 8;
int yellow = 9;
int green = 10;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  digitalWrite(red, HIGH);
  delay(3000); // Red for 3 seconds
  digitalWrite(red, LOW);
  
  digitalWrite(yellow, HIGH);
  delay(1000); // Yellow for 1 second
  digitalWrite(yellow, LOW);
  
  digitalWrite(green, HIGH);
  delay(3000); // Green for 3 seconds
  digitalWrite(green, LOW);
}
