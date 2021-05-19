#include <Servo.h>    // Import the Servo library to control the servo

Servo x;
Servo y;          // Initialise the servo object to control the servo

// Values for microphone
int microphonePin = A2;   // Pin location for microphone
int micValue;
int val = 0;

// Values for low, mid and high microphone
int lowestValue = 300;
int mediumValue = 433;
int highestValue = 566;

// Values for potentiometer
int rotaryPin = 3;  // Pin location for rotarypin1
int rotaryPin1 = A0;    // Pin location for rotarypin
int rotaryXVal = 0;   // variable to store the value coming from the rotary
int rotaryYVal = 0;

// Max/Min values for horizontal motor
int yMin = 0;
int yMax = 200;

// Max/Min values for vertical motor
int xMin = 550;
int xMax = 1023;

void setup() {
  x.attach(3);    // Tell the servo object that we've connected to pin 3
  y.attach(2);   // Connectes the servo1 to pin 2
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

    // Potentiometer values
    rotaryXVal = analogRead(rotaryPin);      // Reads value from rotary pins
    rotaryYVal = analogRead(rotaryPin1);   

    rotaryXVal = constrain(rotaryXVal, xMin, xMax);   // Constraints for X and Y 
    rotaryYVal = constrain(rotaryYVal, yMin, yMax);

    // Potentiometer values -> rotary
    x.write(rotaryXVal);  // passes value for horizontal motor
    y.write(rotaryYVal);  // passes value for vertical motor
}
