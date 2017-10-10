#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);

int IR_L = 0;
int IR_R = 1;

int drive_L =0;   // Drive speed for left wheel
int drive_R = 0;  // Drive speed for right wheel

int baseSpeed = 20; // Base speed of the wheels
int Kp = 2;         // Proportionality constant for control
int driveSetting = 0; // Speed setting for the car

int irThreshold = 120;

byte msg = 1;


void setup() {
  AFMS.begin();
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);


  // Read Serial Data
  if(Serial.available() > 0) {
    msg = Serial.read();
//    driveSetting = int(msg);
//    digitalWrite(LED_BUILTIN, ~digitalRead(LED_BUILTIN));
    Serial.println(msg);
  }



/*  
  // Read-in IR sensor values
  int ir_left = analogRead(IR_L);
  int ir_right = analogRead(IR_R);

  // Compare Sensor Values
  int val = abs(ir_left - ir_right);

  if(ir_left >= irThreshold) {
    // drive right more
    drive_L = (baseSpeed)*driveSetting;
    drive_R = ((val/Kp) + baseSpeed)*driveSetting;
  } else if(ir_right >= irThreshold) {
    // drive left more
    drive_L = ((val/Kp) + baseSpeed)*driveSetting;
    drive_R = (baseSpeed)*driveSetting;
  } else {
    // go forward
    drive_L = (baseSpeed)*driveSetting;
    drive_R = (baseSpeed)*driveSetting;
  }

/*
/*
  Serial.print(drive_L);
  Serial.print(" , ");
  Serial.print(drive_R);
  Serial.println("");
*/

/*
  // Send drive commands to motors
  leftMotor->setSpeed(drive_L);
  rightMotor->setSpeed(drive_R);

  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);

*/
}
