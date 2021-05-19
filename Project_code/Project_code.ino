#include <Servo.h>    // Import the Servo library to control the servo

Servo servo;          // Initialise the servo object to control the servo
Servo servo1;

int rotaryPin = A0; // select the input pin for the rotary
int rotaryPin1 = 3;
int rotaryValue = 0; // variable to store the value coming from the rotary
int rotaryValue1 = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(3);    // Tell the servo object that we've connected to pin 8
  servo.write(0);     // Helps to adjust the initial position
  servo1.attach(2);
  servo1.write(0);
  delay(40);
}

void loop() {
  // read the value from the sensor:  

  rotaryValue = map(rotaryValue, 0, 1023, 0, 255);
  rotaryValue1 = map(rotaryValue1, 0, 1023, 0, 255);
  
  rotaryValue = analogRead(rotaryPin);  // sets the value for the horizontal motor
  rotaryValue1 = analogRead(rotaryPin1);    // Sets the value for the vertical motor

  servo.write(rotaryValue);  // Set the position of the servo
  servo1.write(rotaryValue1);
  
  //Serial.println(rotaryValue);
}
