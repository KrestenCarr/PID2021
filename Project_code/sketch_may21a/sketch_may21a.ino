#include <Servo.h>

//Servo objects created to control the servos
Servo myServo1;
Servo myServo2;

int servo1 = 3; //Digital PWM pin used by the servo 1
int servo2 = 2; //Digital PWM pin used by the servo 2

// Values for microphone
int microphonePin = A2;   // Pin location for microphone
int micValue;
int val = 0;

// Values for low, mid and high microphone
int lowestValue = 300;
int mediumValue = 433;
int highestValue = 566;

int ySpeed = 2;
int xSpeed = 1;

int xMax = 100;
int xMin = 0;

int yMax = 100;
int yMin = 40;

boolean on = true;
int posX = 0;
int posY = 0;

void setup() {
  myServo1.attach(servo1);
  myServo2.attach(servo2);
  pinMode(microphonePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Microphone values
  micValue = analogRead(microphonePin);

  // Thresholds for microphone
  if (micValue > lowestValue) {    // For no detection
  } if (micValue > lowestValue && micValue < mediumValue) {   // For low volume
    Serial.println("Low Volume");
  } if (micValue > mediumValue && micValue < highestValue) {   // For medium volume
    Serial.println("Medium Volume");
  } if (micValue > highestValue) {   // For high volume
    Serial.println("High Volume");
  }

  for (posX = xMin; posX <= xMax; posX += xSpeed) { // goes from 0 degrees to 180 degrees
    myServo1.write(posX);
    posY += ySpeed;
    myServo2.write(posY);
    if (posY >= yMax) {
      ySpeed *= -1;
    }
    if (posY <= yMin) {
      posY = yMin;
      ySpeed *= -1;
    }
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (posX = xMax; posX >= xMin; posX -= xSpeed) { // goes from 180 degrees to 0 degrees
    myServo1.write(posX);              // tell servo to go to position in variable 'pos'
    myServo2.write(posY);
    posY -= ySpeed;
    if (posY >= yMax) {
      ySpeed *= -1;
    }
    if (posY <= yMin) {
      posY = yMin;
      ySpeed *= -1;
    }
    delay(15);                       // waits 15ms for the servo to reach the position
  }

}
