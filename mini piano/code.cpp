#define buzzer 13
#define C_KEY 2
#define D_KEY 4
// define rest similarly

int C_FREQ = 262;
int D_FREQ = 294;
// define rest similarly

void setup() {
  pinMode(C_KEY, INPUT);
  digitalWrite(C_KEY, HIGH);
  // repeat for all keys
}

void loop() {
  if (digitalRead(C_KEY) == LOW) {
    tone(buzzer, C_FREQ);
  } else if (digitalRead(D_KEY) == LOW) {
    tone(buzzer, D_FREQ);
  }
  // repeat for all keys
  else {
    noTone(buzzer);
  }
}
