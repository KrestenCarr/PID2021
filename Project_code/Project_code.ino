#include <Servo.h>    // Import the Servo library to control the servo

Servo servo1;          // Initialise the servo object to control the servo
Servo servo;

// Values for microphone
int microphonePin = A2;   // Pin location for microphone
int micValue;
int val = 0;

// Values for potentiometer
int rotaryPin1 = A0;  // Pin location for rotarypin1
int rotaryPin = 3;    // Pin location for rotarypin
int rotaryValue = 0;   // variable to store the value coming from the rotary
int rotaryValue1 = 0;
int pMin = 0;
int pMax = 180;

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
    if (micValue > 300) {    // For no detection
    } if (micValue > 300 && micValue < 433) {   // For low volume
      Serial.println("Low Volume");
    } if (micValue > 433 && micValue < 566) {   // For medium volume
      Serial.println("Medium Volume");
    } if (micValue > 566 && micValue < 750) {   // For high volume
      Serial.println("High Volume");
    }

    // Potentiometer values
    rotaryValue = analogRead(rotaryPin);      // sets the value for the horizontal motor
    rotaryValue1 = analogRead(rotaryPin1);    // Sets the value for the vertical motor

    rotaryValue = constrain(rotaryValue, 550, 1023);   // Horizontal constraints
    rotaryValue1 = constrain(rotaryValue1, 0, 200);   // Vertical constraints

    // Potentiometer values -> rotary
    servo.write(rotaryValue);  // passes value for horizontal motor
    servo1.write(rotaryValue1);  // passes value for vertical motor
}
