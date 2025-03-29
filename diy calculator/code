#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1, 0};

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int first = 0, second = 0, total = 0;
char op; // Stores the selected operator

void setup() {
    lcd.begin(16, 2);
    lcd.print("Calculator");
    delay(2000);
    lcd.clear();
}

void loop() {
    char key = customKeypad.getKey();

    if (key) {
        if (key >= '0' && key <= '9') {
            first = first * 10 + (key - '0');
            lcd.print(key);
        } else if (key == 'A' || key == 'B' || key == 'C' || key == 'D') {
            op = key;
            lcd.setCursor(0, 1);
            if (key == 'A') lcd.print(" + ");
            if (key == 'B') lcd.print(" - ");
            if (key == 'C') lcd.print(" * ");
            if (key == 'D') lcd.print(" / ");
        } else if (key == '#') { // Equal Button
            switch (op) {
                case 'A': total = first + second; break;
                case 'B': total = first - second; break;
                case 'C': total = first * second; break;
                case 'D': 
                    if (second != 0) total = float(first) / float(second); 
                    else lcd.print(" Invalid");
                    break;
            }
            lcd.setCursor(0, 1);
            lcd.print("Result: ");
            lcd.print(total);
            first = second = total = 0;
        } else if (key == '*') { // Clear Button
            lcd.clear();
            first = second = total = 0;
        }
    }
}
