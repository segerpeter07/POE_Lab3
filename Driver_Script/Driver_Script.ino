#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

int IR_L = 0;
int IR_R = 1;

int drive_L =0;   // Drive speed for left wheel
int drive_R = 0;  // Drive speed for right wheel

int baseSpeed = 50; // Base speed of the wheels
int Kp = 2;         // Proportionality constant for control
int driveSetting = 0;


void setup() {
  AFMS.begin();
  Serial.begin(9600);

}

void loop() {
  // Read Serial Data
  if(Serial.available() > 0) {
    driveSetting = Serial.read();
  }

  // Adjust baseSpeed according to driveSetting
  baseSpeed = baseSpeed*driveSetting;
  
  // Read-in IR sensor values
  ir_left = analogRead(IR_L);
  ir_right = analogRead(IR_R);

  // Compare Sensor Values
  int val = ir_left - ir_right;

  if(val < 0) {
    // drive left wheel more
    drive_L = (val/Kp) + baseSpeed;
    drive_R = baseSpeed;
  } else if(val > 0) {
    // drive right wheel more
    drive_L = baseSpeed;
    drive_R = (val/Kp) + baseSpeed;
  } else {
    // drive both wheels the same amount
    drive_L = baseSpeed;
    drive_R = baseSpeed;
  }

  // Send drive commands to motors
  leftMotor->setSpeed(drive_L);
  rightMotor->setSpeed(drive_R);

  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
}
