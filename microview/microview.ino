#include <MicroView.h>
#include <Keypad.h>

MicroViewWidget *widget;

const int buttonPin = 2;
const int buzzerPin = A0;
const int sensorXPin = A1;
const int sensorYPin = A2;

const int freq = 294;

int buttonState = 0;
int sensorValue = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(sensorXPin, INPUT);
  uView.begin();
  uView.clear(PAGE);
  widget = new MicroViewGauge(32, 24, 0, 1024);
  const byte rows = 4;
  const byte cols = 4;
  char keys[rows][cols] = {
    {'1','2','3','4'},
    {'5','6','7','8'},
    {'9','A','B','C'},
    {'D','E','F','G'}
  };
  byte rowPins[rows] = {5, 4, 3, 2};
  byte colPins[cols] = {8, 7, 6}; //connect to the column pinouts of the keypad
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
}

void loop() {
  buttonState = digitalRead(buttonPin);
  sensorValue= analogRead(sensorXPin);
  widget->setValue(sensorValue);
  int bend = (sensorValue-512)/20;
  
   if (buttonState == HIGH) {
    uView.display();
    tone(buzzerPin, freq + bend);
    //delay(20);
  } else {
    uView.display();
    noTone(buzzerPin);
  }
}
