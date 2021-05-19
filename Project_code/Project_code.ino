#include <Servo.h>    // Import the Servo library to control the servo

Servo servo1;          // Initialise the servo object to control the servo
Servo servo;

// Values for microphone
int microphonePin = A2;   // Pin location for microphone
int micValue;
int val = 0;

// Values for low, mid and high microphone
int lowestValue = 300;
int mediumValue = 433;
int highestValue = 566;

// Values for potentiometer
int rotaryPin1 = A0;  // Pin location for rotarypin1
int rotaryPin = 3;    // Pin location for rotarypin
int rotaryValue = 0;   // variable to store the value coming from the rotary
int rotaryValue1 = 0;

// Max/Min values for horizontal motor
int pMin = 0;
int pMax = 200;

// Max/Min values for vertical motor
int p1Min = 550;
int p1Max = 1023;

void setup() {
  Serial.begin(9600);
  servo.attach(3);    // Tell the servo object that we've connected to pin 3
  servo1.attach(2);   // Connectes the servo1 to pin 2
  delay(40);

  pinMode(microphonePin, INPUT);
}

void loop() {
    // Microphone values
    micValue = analogRead(microphonePin);

    // Thresholds
    if (micValue > lowestValue) {    // For no detection
    } if (micValue > lowestValue && micValue < mediumValue) {   // For low volume
      Serial.println("Low Volume");
    } if (micValue > mediumValue && micValue < highestValue) {   // For medium volume
      Serial.println("Medium Volume");
    } if (micValue > highestValue) {   // For high volume
      Serial.println("High Volume");
    }

    // Potentiometer values
    rotaryValue = analogRead(rotaryPin);      // sets the value for the horizontal motor
    rotaryValue1 = analogRead(rotaryPin1);    // Sets the value for the vertical motor

    rotaryValue = constrain(rotaryValue, p1Min, p1Max);   // Horizontal constraints
    rotaryValue1 = constrain(rotaryValue1, pMin, pMax);   // Vertical constraints

    // Potentiometer values -> rotary
    servo.write(rotaryValue);  // passes value for horizontal motor
    servo1.write(rotaryValue1);  // passes value for vertical motor
}
