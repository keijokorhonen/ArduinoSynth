#include <Keypad.h>
#include "pitches.h"

const int buttonPin = 30;
const int buzzerPin = A0;
const int sensorXPin = A1;
const int sensorYPin = A2;

int freq = 0;

int buttonState = 0;
int sensorValue = 0;

const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','A','B','C'},
  {'D','E','F','G'}
};
byte rowPins[rows] = {52, 50, 48, 46};
byte colPins[cols] = {44, 42, 40, 38};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(sensorXPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  sensorValue= analogRead(sensorXPin);
  char key = keypad.getKey();
  int bend = (sensorValue-512)/20;
  int state = keypad.getState();
  if (key == '1') {
    freq = NOTE_C3;
  }
  if (key == '2') {
    freq = NOTE_D3;
  }
  if (key == '3') {
    freq = NOTE_E3;
  }
  if (key == '4') {
    freq = NOTE_F3;
  }
  if (key == '5') {
    freq = NOTE_G3;
  }
  if (key == '6') {
    freq = NOTE_A3;
  }
  if (key == '7') {
    freq = NOTE_B3;
  }
  if (key == '8') {
    freq = NOTE_C4;
  }
  if (key == '9') {
    freq = NOTE_D4;
  }
  if (key == 'A') {
    freq = NOTE_E4;
  }
  if (key == 'B') {
    freq = NOTE_F4;
  }
  if (key == 'C') {
    freq = NOTE_G4;
  }
  if (key == 'D') {
    freq = NOTE_A4;
  }
  if (key == 'E') {
    freq = NOTE_B4;
  }
  if (key == 'F') {
    freq = NOTE_C5;
  }
  if (key == 'G') {
    freq = NOTE_D5;
  }
  if (state == 1 || state == 2) {
    tone(buzzerPin, freq);
  } else {
    noTone(buzzerPin);
  }
}
