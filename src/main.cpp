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
// leftFrontMotor       motor         1               
// rightFrontMotor      motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  while (1 == 1)
  {
    leftFrontMotor.spin(directionType::fwd, Controller1.Axis3.value(),velocityUnits::pct);
    rightFrontMotor.spin(directionType::fwd, Controller1.Axis2.value(),velocityUnits::pct);

    // Left Front Motor Code. Moves foward and backwards.
    if(Controller1.ButtonL1.pressing())
    {
      leftFrontMotor.spin(directionType::fwd, 50 , velocityUnits::pct);
    }
    else if(Controller1.ButtonL2.pressing())
    {
      leftFrontMotor.spin(directionType::rev, 50 , velocityUnits::pct);
    }
    else
    {
      leftFrontMotor.stop(brakeType::hold);
    }

     // Left Front Motor Code. Moves foward and backwards.
    if(Controller1.ButtonR1.pressing())
    {
      rightFrontMotor.spin(directionType::fwd, 50 , velocityUnits::pct);
    }
    else if(Controller1.ButtonR2.pressing())
    {
      rightFrontMotor.spin(directionType::rev, 50 , velocityUnits::pct);
    }
    else
    {
      rightFrontMotor.stop(brakeType::hold);
    }

  }
  vexcodeInit();
  // hello.
  
}
