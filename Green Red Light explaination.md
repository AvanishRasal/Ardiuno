# Button-Controlled Lights using Arduino

## Overview
This Arduino program demonstrates how to control two lights (red and green) using two buttons. When a button is pressed, the corresponding light turns on at maximum brightness using Pulse Width Modulation (PWM). This project is perfect for beginners who want to understand button inputs and light outputs with an Arduino. It could be adapted for projects like traffic signals or custom indicators.

---

## Code
```cpp
// Pin declarations for buttons and lights
int redLightButton = 2;   // Pin connected to the red light button
int redLight = 3;         // Pin connected to the red light
int greenLight = 5;       // Pin connected to the green light
int greenLightButton = 6; // Pin connected to the green light button

void setup() {
  // Configure pins for buttons as input
  pinMode(redLightButton, INPUT);
  pinMode(greenLightButton, INPUT);

  // Configure pins for lights as output
  pinMode(redLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
}

void loop() {
  // Read the states of the buttons
  int redLightButtonState = digitalRead(redLightButton);
  int greenLightButtonState = digitalRead(greenLightButton);

  // Turn off both lights by default
  analogWrite(redLight, 0);
  analogWrite(greenLight, 0);

  // Check the state of the red light button
  if (redLightButtonState == HIGH) {
    analogWrite(redLight, 255); // Turn on the red light at maximum brightness
  }

  // Check the state of the green light button
  if (greenLightButtonState == HIGH) {
    analogWrite(greenLight, 255); // Turn on the green light at maximum brightness
  }
}
