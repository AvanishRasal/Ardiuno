

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
  delay(100);  // delay in htbetween reads for stability
}
