# Arduino Mouse Button Emulator

## Introduction

Hi! I'm learning basic programming of Arduino Uno board. 

This project emulates mouse button presses using pushbuttons connected to the Arduino. When you press the buttons, the Arduino sends messages to the computer.

## Components Needed

- Arduino Uno board
- USB cable to connect Arduino to computer
- Pushbuttons (2)
- Jumper wires
- Breadboard

## Circuit Diagram

Connect the pushbuttons to the Arduino as follows:
- Left button to digital pin 4
- Right button to digital pin 2

## Pushbutton Placement

!Pushbutton Placement

As shown image below are connections made ![This is the image](image.jpg?raw=true "BreadBoard")

### Connections

1. **Left Button**:
   - Connect one leg of the left pushbutton to digital pin 4 on the Arduino.
   - Connect the other leg of the left pushbutton to the ground (GND) on the Arduino.

2. **Right Button**:
   - Connect one leg of the right pushbutton to digital pin 2 on the Arduino.
   - Connect the other leg of the right pushbutton to the ground (GND) on the Arduino.

3. **Power Connections**:
   - Connect the 5V pin on the Arduino to the positive rail on the breadboard.
   - Connect the GND pin on the Arduino to the negative rail on the breadboard.

## Code Explanation 

Here's the code for the project:

```cpp
// digital pin 2 has a pushbutton attached to it. Give it a name:
int Leftbutton = 4;
int Rightbutton = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(Leftbutton, INPUT);
  pinMode(Rightbutton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int leftbuttonState = digitalRead(Leftbutton);
  int rightbuttonState = digitalRead(Rightbutton); 
  // print out the state of the button
  if (leftbuttonState == 1)
    Serial.println("Left pressed ");
  delay(100);  // delay in between reads for stability

  if (rightbuttonState == 1) {
    Serial.println("Right Pressed  ");
  }
  delay(100);  // delay in between reads for stability
}

![This is the image](mouseworks.mp4?raw=true "working")
