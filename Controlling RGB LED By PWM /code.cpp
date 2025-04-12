// RGB LED Pins
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// Function to set RGB color
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Red
  setColor(255, 0, 0);
  delay(1000);

  // Green
  setColor(0, 255, 0);
  delay(1000);

  // Blue
  setColor(0, 0, 255);
  delay(1000);

  // Yellow (Red + Green)
  setColor(255, 255, 0);
  delay(1000);

  // Cyan (Green + Blue)
  setColor(0, 255, 255);
  delay(1000);

  // Magenta (Red + Blue)
  setColor(255, 0, 255);
  delay(1000);

  // White (All colors)
  setColor(255, 255, 255);
  delay(1000);

  // Off (All zeros)
  setColor(0, 0, 0);
  delay(1000);
}
