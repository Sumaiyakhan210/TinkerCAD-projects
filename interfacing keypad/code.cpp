#include <Keypad.h>  // Include the keypad library

// Define the number of rows and columns on the keypad
const byte ROWS = 4;
const byte COLS = 4;

// Define the keymap (characters on the keypad)
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},  // A = +
  {'4', '5', '6', 'B'},  // B = -
  {'7', '8', '9', 'C'},  // C = *
  {'*', '0', '#', 'D'}   // D = /
};

// Connect row and column pins on Arduino
byte rowPins[ROWS] = {9, 8, 7, 6};     // R1, R2, R3, R4
byte colPins[COLS] = {5, 4, 3, 2};     // C1, C2, C3, C4

// Create the keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);  // Start the Serial Monitor
}

void loop() {
  char key = keypad.getKey();  // Get the key pressed

  if (key) {  // If a key is pressed
    Serial.println("Key Pressed: ");
    Serial.println(key);
  }
}

