#include <Servo.h>       // Include the Servo library

Servo myservo;           // Create servo object to control a servo
int pos = 0;             // Variable to store servo position

void setup() {
  myservo.attach(7);     // Attach servo to pin 7
}

void loop() {
  // Rotate from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos++) {
    myservo.write(pos);
    delay(15);           // Wait 15ms between steps
  }
  
  delay(3000);           // Wait 3 seconds at max angle

  // Rotate back from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos--) {
    myservo.write(pos);
    delay(15);
  }

  delay(3000);           // Wait 3 seconds at min angle
}
