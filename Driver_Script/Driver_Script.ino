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
int driveSetting = 0;

int irThreshold = 120;


void setup() {
  AFMS.begin();
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  // Read Serial Data
//  if(Serial.available() > 0) {
//    driveSetting = Serial.read();
//  }
  digitalWrite(8, HIGH);

  driveSetting = 1;

  // Adjust baseSpeed according to driveSetting
  baseSpeed = baseSpeed*driveSetting;
  
  // Read-in IR sensor values
  int ir_left = analogRead(IR_L);
  int ir_right = analogRead(IR_R);

  Serial.print(ir_left);
  Serial.print(" , ");
  Serial.print(ir_right);
  Serial.println("");

  // Compare Sensor Values
  int val = abs(ir_left - ir_right);

//  if(ir_left < ir_right) {
//    // drive left wheel more
//    drive_L = (val/Kp) + baseSpeed;
//    drive_R = baseSpeed;
//  } else if(val > 0) {
//    // drive right wheel more
//    drive_L = baseSpeed;
//    drive_R = (val/Kp) + baseSpeed;
//  } else {
//    // drive both wheels the same amount
//    drive_L = baseSpeed;
//    drive_R = baseSpeed;
//  }

  if(ir_left >= irThreshold) {
    // drive right more
    drive_L = baseSpeed;
    drive_R = (val/Kp) + baseSpeed;
  } else if(ir_right >= irThreshold) {
    // drive left more
    drive_L = (val/Kp) + baseSpeed;
    drive_R = baseSpeed;
  } else {
    // go forward
    drive_L = baseSpeed;
    drive_R = baseSpeed;
  }

  Serial.print(drive_L);
  Serial.print(" , ");
  Serial.print(drive_R);
  Serial.println("");

  // Send drive commands to motors
  leftMotor->setSpeed(drive_L);
  rightMotor->setSpeed(drive_R);

  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
}
