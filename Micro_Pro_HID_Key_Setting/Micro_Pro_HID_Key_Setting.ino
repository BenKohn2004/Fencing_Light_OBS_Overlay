// Arduino Leonardo
// Receives inputs and acts as a Human Input Device (HID)
// Sends HotKeys to computer as a keyboard to change visibility
// of overlay lights
// Used to set the hotkeys in OBS

#include <Keyboard.h>

//Pins Used to Input Lights
const int buttonPin2 = 2;
const int buttonPin3 = 6;
const int buttonPin4 = 4;
const int buttonPin5 = 5;

// Pins are initially set to Low
int pressedPin2 = LOW;
int pressedPin3 = LOW;
int pressedPin4 = LOW;
int pressedPin5 = LOW;

// Last State of Pins initially set to LOW
int lastState2 = LOW;
int lastState3 = LOW;
int lastState4 = LOW;
int lastState5 = LOW;

// Last time the button was pressed
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long lastDebounceTime4 = 0;
unsigned long lastDebounceTime5 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting!");

  Serial.println("Setting Pin Modes.");
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);

  Serial.println("Setup Complete!");
}

void loop() {
  // put your main code here, to run repeatedly:

  // Key Assign and Test
  delay(1000);
  Keyboard.press(KEY_F13);
  delay(1000);
  Keyboard.release(KEY_F13);
  delay(1000);
  Keyboard.press(KEY_F14);
  delay(1000);
  Keyboard.release(KEY_F14);
  delay(1000);
  Keyboard.press(KEY_F15);
  delay(1000);
  Keyboard.release(KEY_F15);
  delay(1000);
  Keyboard.press(KEY_F16);
  delay(1000);
  Keyboard.release(KEY_F16);
  delay(1000);
  Keyboard.press(KEY_F17);
  delay(1000);
  Keyboard.release(KEY_F17);
  delay(1000);
  Keyboard.press(KEY_F18);
  delay(1000);
  Keyboard.release(KEY_F18);
  delay(1000);
  Keyboard.press(KEY_F19);
  delay(1000);
  Keyboard.release(KEY_F19);
  delay(1000);
  Keyboard.press(KEY_F20);
  delay(1000);
  Keyboard.release(KEY_F20);

}
