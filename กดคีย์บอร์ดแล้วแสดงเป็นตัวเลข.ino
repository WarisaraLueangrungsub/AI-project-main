#include <Keypad.h>

const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pins for the 74HC595 Shift Register
const int dataPin = A2;
const int latchPin = A3;
const int clockPin = A4;

// Setup the keypad to not use any direct pins
byte rowPins[rows] = {255, 255, 255, 255};  // dummy values
byte colPins[cols] = {255, 255, 255, 255};  // dummy values
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

const int digit1Pins[] = {2, 3, 4, 5, 6, 7, 8};
const int digit2Pins[] = {9, 10, 11, 12, 13, A0, A1};

int counter = 0;

const byte digitPatterns[] = {
  B11000000, // 0
  B11111001, // 1
  B10100100, // 2
  B10110000, // 3
  B10011001, // 4
  B10010010, // 5
  B10000010, // 6
  B11111000, // 7
  B10000000, // 8
  B10010000  // 9
};

void setup() {
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  // Assuming your column pins are connected with pull-up resistors
  for (byte i = 0; i < cols; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (byte i = 0; i < rows; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, ~(1 << i));  // Set one row at a time
    digitalWrite(latchPin, HIGH);
    delay(1);  // Small delay for stability

    for (byte j = 0; j < cols; j++) {
      if (digitalRead(colPins[j]) == LOW) { 
        char key = keys[i][j];
        Serial.println(key);
        delay(200);  // Debouncing delay
      }
    }
  }
}
