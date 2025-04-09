// Pin Definitions
const int buttonPin = 2;  // Push button connected to pin 2
const int buzzerPin = 9;  // Buzzer connected to pin 9

// Variable to store button state
int buttonState = 0;

void setup() {
  // Set the button pin as input and buzzer pin as output
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the button state
  buttonState = digitalRead(buttonPin);
  
  // Check if the button is pressed
  if (buttonState == HIGH) {
    // Play a sound on the buzzer
    tone(buzzerPin, 1000);  // 1000Hz frequency
  } else {
    // Stop the sound if the button is not pressed
    noTone(buzzerPin);
  }
}

