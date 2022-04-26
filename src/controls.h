/*
  controls.h
  Code for controlling the robot with the handheld controller
*/

#include "vex.h"
using namespace vex;

void moveWheels(void) {
  // left analog stick uses axis 3 (up and down) and axis 4 (left and right)
  // right analog stick uses axis 2 (up and down) and axis 1 (left and right)
  // .position() method gives a result between -100 and 100
  // syntax: motor.spin(Direction, velocity, velocityUnits);

  // uses the left analog stick
  // up is forward (+), down is backward (-), right is rightward (+), left is leftward (-)
  leftWheels.spin(directionType::fwd, (Controller1.Axis3.position(pct) - Controller1.Axis4.position(pct)) / 2, pct);
  rightWheels.spin(directionType::fwd, (Controller1.Axis3.position(pct) + Controller1.Axis4.position(pct)) / 2, pct);
}

void moveArm(const int armMotorSpeed) {
  // if L1 is triggered then move the arm up
  // if L2 is triggered then move the arm down
  // if nothing is pressed, hold the arm in the current position where it was left off.
  if(Controller1.ButtonL1.pressing())
  {
    armMotor.spin(directionType::fwd, armMotorSpeed,velocityUnits::pct);
  }
  else if(Controller1.ButtonL2.pressing())
  {
    armMotor.spin(directionType::rev, armMotorSpeed,velocityUnits::pct);
  }
  else
  {
    armMotor.stop(brakeType::hold);
  }
}

void moveChain(const int chainMotorSpeed) {
  // if R1 is triggered then move the arm up
  // if R2 is triggered then move the arm down
  // if nothing is pressed, hold the arm in the current position where it was left off.

  if(Controller1.ButtonR1.pressing())
  {
    chainMotor.spin(directionType::fwd, chainMotorSpeed,velocityUnits::pct);
  }
  else if(Controller1.ButtonR2.pressing())
  {
    chainMotor.spin(directionType::rev, chainMotorSpeed,velocityUnits::pct);
  }
  else
  {
    chainMotor.stop(brakeType::hold);
  }
}

void controls(void) {
  // we want to adjust the speed for the arm and the chain motor.
  // Therefore we can set separate variables for this.
  int armMotorSpeed = 15;
  int chainMotorSpeed = 70;

  moveWheels();
  moveArm(armMotorSpeed);
  moveChain(chainMotorSpeed);
}
