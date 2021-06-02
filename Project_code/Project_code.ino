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
int val = 0;

// Values for potentiometers
int potentiometer1 = A6;
int potentiometer2 = A0;

float rotaryValue1 = 50;  // Variables for potentiometer1
float rotaryValue2 = 90;  // Variables for potentiometer2

// Values for low, mid and high microphone
int lowestValue = 300;
int mediumValue = 433;
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
  // Microphone values
  micValue = analogRead(microphonePin);

  rotaryValue1 = analogRead(potentiometer1);
  rotaryValue2 = analogRead(potentiometer2);

  if (rotaryValue1 < 77 && rotaryValue1 > 40) {
    myServo1.write(rotaryValue1);   // Top: 40. Bottom: 77.
  }

  if (rotaryValue2 > 77 && rotaryValue2 < 109) {
    myServo2.write(rotaryValue2);   // Top: 77. Bottom: 109.
  }

  //Serial.println(rotaryValue1);

  posX = posX + xSpeed;
  posY = posY + ySpeed;
  myServo3.write(posX);
  myServo4.write(posY);


  /*
    // Thresholds for microphone
    if (micValue > lowestValue) {    // For no detection
    } if (micValue > lowestValue && micValue < mediumValue) {   // For low volume
      Serial.println("Low Volume");
    } if (micValue > mediumValue && micValue < highestValue) {   // For medium volume
      Serial.println("Medium Volume");
    } if (micValue > highestValue) {   // For high volume
      Serial.println("High Volume");
    }

  */


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


  /*
    while (true) {
      rotaryValue1 = analogRead(potentiometer2);
      rotaryValue2 = analogRead(potentiometer1);

      myServo3.write(rotaryValue1);   // Left player
      myServo4.write(rotaryValue2);   // Right player
    }
  */

  /*
      for (posX = xMin; posX <= xMax; posX += xSpeed) { // goes from 0 degrees to 180 degrees
      myServo3.write(posX);
      posY += ySpeed;
      myServo4.write(posY);
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
      myServo3.write(posX);              // tell servo to go to position in variable 'pos'
      myServo4.write(posY);
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
  */

}
