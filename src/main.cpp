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

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 272;

// Convert degrees to radians
inline double to_radians(double degrees) {
  return degrees * (M_PI / 180.0);
}

// Draw a gear logo on the vex brain
void drawLogo(const int teeth=12, const int subtending_angle=20, const int minor_radius=80, const int major_radius=100) {

  // Prepare screen for drawing
  Brain.Screen.clearScreen();
  Brain.Screen.setPenColor(black);
  Brain.Screen.setPenWidth(3);
  Brain.Screen.setFont(monoL);

  // Draw inner circle of the gear
  Brain.Screen.drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, minor_radius);

  // Angle in degrees between teeth of gear
  const int angle_between_teeth = int(360 / teeth);

  // Array to store gear coordinates
  int gear_coords[361][2];

  // Loop over degrees in the gear circle
  for (int i=0; i < 360; i++) {

    // Determine position in current gear cycle, since they're periodic
    const int cycle_position = i % angle_between_teeth;
    int r = major_radius;

    // Determine radius
    if (cycle_position < 5) {
      r += cycle_position * 4;
    } else if (cycle_position < subtending_angle - 5) {
      r += 20;
    } else if (cycle_position < subtending_angle) {
      r += (subtending_angle - cycle_position) * 4;
    }

    // Compute the current point on the gear
    const int x_0 = r * cos(to_radians(i)) + SCREEN_WIDTH / 2;
    const int y_0 = r * sin(to_radians(i)) + SCREEN_HEIGHT / 2;
    gear_coords[i][0] = x_0, gear_coords[i][1] = y_0;
  }

  // Close loop by adding first point to the end
  gear_coords[360][0] = gear_coords[0][0], gear_coords[360][1] = gear_coords[0][1];

  // Draw lines between consecutive pairs of points
  for (int i = 0; i < 360; i++) {
    Brain.Screen.drawLine(gear_coords[i][0], gear_coords[i][1], gear_coords[i + 1][0], gear_coords[i + 1][1]);
  }

  Brain.Screen.setCursor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  Brain.Screen.print("ENGR\nCLUB");
}

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
  drawLogo();
}
