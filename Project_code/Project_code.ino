#include <Servo.h>    // Import the Servo library to control the servo

Servo servo1;          // Initialise the servo object to control the servo
Servo servo;

int rotaryPin1 = A0; // select the input pin for the rotary
int rotaryPin = 3;
int rotaryValue = 0; // variable to store the value coming from the rotary
int rotaryValue1 = 0;
int pMin = 0;
int pMax = 180;

void setup() {
  Serial.begin(9600);
  servo.attach(3);    // Tell the servo object that we've connected to pin 3
  servo1.attach(2);   // Connectes the servo1 to pin 2
  delay(40);
}

void loop() {
  // read the value from the sensor:  
  
  rotaryValue = analogRead(rotaryPin);      // sets the value for the vertical motor
  rotaryValue1 = analogRead(rotaryPin1);    // Sets the value for the horizontal motor  

  rotaryValue = constrain(rotaryValue, 550, 1023);   // Uses constrain to keep its value
  rotaryValue1 = constrain(rotaryValue1, 0, 150);

  servo.write(rotaryValue);  // Position for servo
  servo1.write(rotaryValue1);  // Set the position of the servo1
}
