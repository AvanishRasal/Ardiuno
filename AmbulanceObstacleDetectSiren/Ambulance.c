long duration;
int distance;

const int trigPin = 10;
const int echoPin = 11;
const int buzzer = 9;
const int blueLed = 13;
const int redLed = 7;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(blueLed, OUTPUT);
    pinMode(redLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance < 30) {
    Serial.println("Obstacle Detected");

    playPoliceSiren(); //  Siren effect

    delay(1000); // Delay to prevent continuous re-triggering
  } else {
    Serial.println("Waiting for obstacle detect");
  }

  delay(200);
}

void playPoliceSiren() {
  for (int repeat = 0; repeat < 10; repeat += 1) {
    // Sweep up (WEEEEE)
    for (int freq = 600; freq <= 1200; freq += 10) {

      digitalWrite(redLed, HIGH);
      tone(buzzer, freq);
      delay(5);
       digitalWrite(redLed, LOW);
    }

    // Sweep down (WOOOOO)
    for (int freq = 1200; freq >= 600; freq -= 10) {
       digitalWrite(blueLed, HIGH);
    
      tone(buzzer, freq);
      delay(5);
       digitalWrite(blueLed, LOW);
    }
  }
  noTone(buzzer); // Turn off buzzer at end
}

