// Arduino Leonardo
// Receives inputs and acts as a Human Input Device (HID)
// Sends HotKeys to computer as a keyboard to change visibility
// of overlay lights

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
//  Serial.begin(9600);
  Serial.begin(115200);
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

  pressedPin2 = digitalRead(buttonPin2);
  pressedPin3 = digitalRead(buttonPin3);
  pressedPin4 = digitalRead(buttonPin4);
  pressedPin5 = digitalRead(buttonPin5);

// BUTTONS
// Toggles the Green Light
  if (pressedPin2 != lastState2)
  {
    if (pressedPin2 == HIGH)
    {
      Keyboard.press(KEY_F13);
      Keyboard.release(KEY_F13);
    }
    if (pressedPin2 == LOW)
    {
      Keyboard.press(KEY_F14);
      Keyboard.release(KEY_F14);
    }
  }

  // Toggles the Red Light
  if (pressedPin3 != lastState3)
  {
    if (pressedPin3 == HIGH)
    {
      Keyboard.press(KEY_F15);
      Keyboard.release(KEY_F15);
    }
    if (pressedPin3 == LOW)
    {
      Keyboard.press(KEY_F16);
      Keyboard.release(KEY_F16);
    }
  }

  // Toggles the Green White Light
  if (pressedPin4 != lastState4)
  {
    if (pressedPin4 == HIGH)
    {
      Keyboard.press(KEY_F19);
      Keyboard.release(KEY_F19);
    }
    if (pressedPin4 == LOW)
    {
      Keyboard.press(KEY_F20);
      Keyboard.release(KEY_F20);
    }
  }

  // Toggles the Red White Light
  if (pressedPin5 != lastState5)
  {
    if (pressedPin5 == HIGH)
    {
      Keyboard.press(KEY_F17);
      Keyboard.release(KEY_F17);
    }
    if (pressedPin5 == LOW)
    {
      Keyboard.press(KEY_F18);
      Keyboard.release(KEY_F18);
    }
  }

  // BUTTON STATE MANAGEMENT
  // Save the latest reading
  lastState2 = pressedPin2;
  lastState3 = pressedPin3;
  lastState4 = pressedPin4;
  lastState5 = pressedPin5;

}
