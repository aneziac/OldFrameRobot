/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Nate                                                      */
/*    Created:      Thu Feb 03 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// leftFrontMotor       motor         11              
// leftBackMotor        motor         12              
// rightFrontMotor      motor         1               
// rightBackMotor       motor         2               
// armMotor             motor29       H               
// clawMotor            motor29       A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // hello.
  Brain.Screen.print("Movement Script");
  
  // creates a group of motors for each side.
  motor_group leftSideMotors = motor_group(leftFrontMotor, leftBackMotor);
  motor_group rightSideMotors = motor_group(rightFrontMotor, rightBackMotor);

  // Creates a forever loop to keep the program running, until a specific condition is used to stop it.
  while(1)
  {
    // left analog stick uses axis 3 (up and down) and axis 4 (left and right)
    // PORT 11 - 20 are on the left side
    // PORT 1 - 10 are on the right side
    // right analog stick uses axis 2 (up and down) and axis 1 (left and right)
    // motor.spin( Direction, velocity, velocityUnits);

    //uses the left analog stick
    // (up or down) + number (+ direction means right)
    // (up or down) - number (- direction means left)
    leftSideMotors.spin(forward, Controller1.Axis3.position() + Controller1.Axis4.position(), pct);
    rightSideMotors.spin(forward, Controller1.Axis3.position() + Controller1.Axis4.position(), pct);

    armMotor.spin(forward, Controller1.Axis2.position(), pct);
    clawMotor.spin(forward, Controller1.Axis1.position(), pct);

    // Want to learn: What can I do to change how fast the motors are turning?
    // How can I make the claw of the robot close? (gears? Program?)

    
    wait(20,msec); // for refreshing the program.
    

  }
  vexcodeInit();
  // hello.
  
}
