#include <Servo.h>

//Servo objects created to control the servos
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;

int servo1 = 3; //Digital PWM pin used by the servo 1
int servo2 = 2; //Digital PWM pin used by the servo 2
int servo3 = 4; //Digital PWM pin used by the servo 3
int servo4 = 5; //Digital PWM pin used by the servo 4

// Values for microphone
int microphonePin = A2;   // Pin location for microphone
int micValue;
float shoutVal;

// Values for potentiometers
int potentiometer1 = A6;
int potentiometer2 = A0;

float rotaryValue1 = 50;  // Variables for potentiometer1
float rotaryValue2 = 90;  // Variables for potentiometer2

// Values for low, mid and high microphone
int lowestValue = 300;
int mediumValue = 200;
int highestValue = 566;

float ySpeed = 0.01;
float xSpeed = 0.01;

float xMax = 71;
float xMin = -5;

float yMax = 85;
float yMin = 30;

boolean on = true;
float posX = 40;
float posY = 50;


void setup() {
  myServo1.attach(servo1);
  myServo2.attach(servo2);
  myServo3.attach(servo3);
  myServo4.attach(servo4);

  pinMode(microphonePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  rotaryValue1 = analogRead(potentiometer1);
  rotaryValue2 = analogRead(potentiometer2);

  if (rotaryValue1 < 77 && rotaryValue1 > 40) {
    myServo1.write(rotaryValue1);   // Top: 40. Bottom: 77.
  }

  if (rotaryValue2 > 77 && rotaryValue2 < 109) {
    myServo2.write(rotaryValue2);   // Top: 77. Bottom: 109.
  }

  posX = posX + xSpeed;
  posY = posY + ySpeed;
  myServo3.write(posX);
  myServo4.write(posY);

  if (posX > xMax) {
    xSpeed *= -1;
  }

  if (posX < xMin) {
    xSpeed *= -1;
  }

  if (posY > yMax) {
    ySpeed *= -1;
  }

  if (posY < yMin) {
    ySpeed *= -1;
  }

  if (posY > 57.5 && rotaryValue2 > 93 || posY < 57.5 && rotaryValue2 < 93) {
    if (posX < 61 && posX > 60) {

      micValue = analogRead(microphonePin);

      xSpeed *= -1;

      if (micValue < mediumValue) {
        if (xSpeed > 0) {
          xSpeed = 0.01;
        } else {
          xSpeed = -0.01;
        }
      } else if (micValue > mediumValue) {
        if (xSpeed > 0) {
          xSpeed = 0.05;
        } else {
          xSpeed = -0.05;
        }
      }
    }
  }

  if (posY > 57.5 && rotaryValue1 > 58.5 || posY < 57.5 && rotaryValue1 < 58.5) {
    if (posX < 8 && posX > 7) {

      micValue = analogRead(microphonePin);

      xSpeed *= -1;

      if (micValue < mediumValue) {
        if (xSpeed > 0) {
          xSpeed = 0.01;
        } else {
          xSpeed = -0.01;
        }
      } else if (micValue > mediumValue) {
        if (xSpeed > 0) {
          xSpeed = 0.05;
        } else {
          xSpeed = -0.05;
        }
      }
    }
  }
}
