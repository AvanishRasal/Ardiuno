# Ultrasonic Sensor with Buzzer

This project uses an ultrasonic sensor to detect objects and triggers a buzzer if an object is closer than 30 cm.

## Code

```cpp
long duration;
int distance;

const int trigPin = 10;
const int echoPin = 11;
int buzzer = 9;

void setup() {
  // Put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  if (distance < 30) {
    Serial.print("object detected \n");

    digitalWrite(buzzer, 1);
    delayMicroseconds(100);
    digitalWrite(buzzer, 0);
    delayMicroseconds(100);
  } else {
    Serial.print("nothing detected \n");
  }
}

## How It Works

### Ultrasonic Sensor
- The sensor sends out a sound wave and measures the time it takes for the wave to return after hitting an object.
- The distance is calculated using the formula: `distance = duration * 0.034 / 2`.

### Buzzer
- The buzzer is triggered to beep when the detected object is closer than 30 cm.

### Serial Output
- Messages are printed to the Serial Monitor indicating whether an object was detected.

## Components Required
- Ultrasonic Sensor (e.g., HC-SR04)
- Buzzer
- Arduino Board
- Connecting Wires

## Setup
1. Connect the `trigPin` and `echoPin` of the ultrasonic sensor to digital pins 10 and 11 of the Arduino, respectively.
2. Connect the buzzer to digital pin 9.
3. Upload the code to your Arduino board.

