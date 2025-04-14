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

