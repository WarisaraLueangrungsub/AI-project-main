const int digit2Pins[] = {A5, 3, 4, 5, 6, 7, 8}; // Pins for digit cathodes (1st digit)
const int digitPins[] = {9, 10, 11, 12, 13, A0, A1}; // Pins for digit cathodes (2nd digit)

const byte digitPatterns[] = {
  B00111111, //0
B00000110, //1
B01011011, //2
B01001111, //3
B01100110, //4
B01101101, //5
B01111101, //6
B00000111, //7
B01111111, //8
B01101111, //9
};

const int switchAPin = A2; // Switch 1 is connected to pin 2
const int switchBPin = A3; // Switch 2 is connected to pin 3
const int switchCPin = A4; // Switch 3 is connected to pin 4

int counter = 0; // Counter variable to keep track of the displayed number

void setup() {
  pinMode(2,OUTPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(digitPins[i], OUTPUT);
    pinMode(digit2Pins[i], OUTPUT);
  }
  
  pinMode(switchAPin, INPUT_PULLUP); // Enable the internal pull-up resistor for switch A
  pinMode(switchBPin, INPUT_PULLUP); // Enable the internal pull-up resistor for switch B
  pinMode(switchCPin, INPUT_PULLUP); // Enable the internal pull-up resistor for switch C
  
  displayNumber(counter); // Display the initial value of the counter
}

void loop() {
  // Read the state of switch A
  if (digitalRead(switchAPin) == LOW) {
    counter++; // Increment the counter when switch A is pressed
    if (counter > 99) {
      counter = 99; // Limit the counter to 99
    }
    displayNumber(counter); // Update the displayed number
    delay(200); // Delay for debouncing
  }
  
  // Read the state of switch B
  if (digitalRead(switchBPin) == LOW) {
    counter--; // Decrement the counter when switch B is pressed
    if (counter < 0) {
      counter = 0; // Limit the counter to 0
    }
    displayNumber(counter); // Update the displayed number
    delay(200); // Delay for debouncing
  }
  
  // Read the state of switch C
  if (digitalRead(switchCPin) == LOW) {
    counter = 0; // Reset the counter to 0 when switch C is pressed
    displayNumber(counter); // Update the displayed number
    delay(200); // Delay for debouncing
  }
}

void displayNumber(int number) {
  int tensDigit = number / 10;
  int onesDigit = number % 10;
  for (int i = 0; i < 7; i++) {
    digitalWrite(digitPins[i], bitRead(digitPatterns[onesDigit], i));
    digitalWrite(digit2Pins[i], bitRead(digitPatterns[tensDigit], i));
  }
}
