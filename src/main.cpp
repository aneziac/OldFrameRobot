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
// leftBackMotor        motor         2               
// rightFrontMotor      motor         3               
// rightBackMotor       motor         4               
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
    // right analog stick uses axis 2 (up and down) and axis 1 (left and right)
    // motor.spin( Direction, velocity, velocityUnits);

    //uses the left analog stick
    leftSideMotors.spin(forward, Controller1.Axis3.position() + Controller1.Axis4.position(), pct);
    rightSideMotors.spin(forward, Controller1.Axis3.position() + Controller1.Axis4.position(), pct);

    wait(20,msec); // for refreshing the program.
    

  }

}
