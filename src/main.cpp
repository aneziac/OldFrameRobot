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

  // Draw inner circle of the gear
  Brain.Screen.drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, minor_radius);

  // Angle in degrees between teeth of gear
  const int angle_between_teeth = int(360 / teeth);

  // Loop over degrees in the gear circle
  for (int i=0; i < 360; i++) {

    // Determine position in current gear cycle, since they're periodic
    int cycle_position = i % angle_between_teeth;
    int r = major_radius;

    // Determine radius
    if (cycle_position < 5) {
      r += cycle_position * 4;
    } else if (cycle_position < subtending_angle - 5) {
      r += 20;
    } else if (cycle_position < subtending_angle) {
      r += (subtending_angle - cycle_position) * 4;
    }

    // Compute the current and next point on the gear
    int x_0 = r * cos(to_radians(i)) + SCREEN_WIDTH / 2;
    int y_0 = r * sin(to_radians(i)) + SCREEN_HEIGHT / 2;
    int x_1 = r * cos(to_radians(i + 1)) + SCREEN_WIDTH / 2;
    int y_1 = r * sin(to_radians(i + 1)) + SCREEN_HEIGHT / 2;

    // Draw a line between those points
    Brain.Screen.drawLine(x_0, y_0, x_1, y_1);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  drawLogo();
}
