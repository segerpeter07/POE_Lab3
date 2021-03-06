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

int baseSpeed = 10; // Base speed of the wheels
int Kp = 2;         // Proportionality constant for control
int driveSetting = 0; // Speed setting for the car

int irThreshold = 350;

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
    driveSetting = int(msg) - 48;
    Serial.println(driveSetting);
  }


  // Read-in IR sensor values
  int ir_left = analogRead(IR_L);
  int ir_right = analogRead(IR_R);

  // Compare Sensor Values
  int val = abs(ir_left - ir_right);

  if(ir_left >= irThreshold) {
    drive_R = -(baseSpeed)*driveSetting;
    drive_L = (Kp*baseSpeed)*driveSetting;
  } else if(ir_right >= irThreshold) {
    drive_L = -(baseSpeed)*driveSetting;
    drive_R = (Kp*baseSpeed)*driveSetting;
  } else {
    drive_L = (baseSpeed)*driveSetting;
    drive_R = (baseSpeed)*driveSetting;
  }

  // Send drive commands to motors
  leftMotor->setSpeed(abs(drive_L));
  rightMotor->setSpeed(abs(drive_R));


  // Send data over serial
  Serial.print(ir_left);
  Serial.print(" , ");
  Serial.print(ir_right);
  Serial.print(" , ");
  Serial.print(drive_L);
  Serial.print(" , ");
  Serial.print(drive_R);
  Serial.println("");


  if(drive_L < 0) {
    leftMotor->run(BACKWARD);
  } else {
    leftMotor->run(FORWARD);
  }

  if(drive_R < 0) {
    rightMotor->run(BACKWARD);
  } else {
    rightMotor->run(FORWARD);
  }
}
