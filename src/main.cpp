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
// robotEyes            vision        13              
// armMotor             motor         16              
// chainMotor           motor         17              
// leftWheels           motor         1               
// rightWheels          motor         11              
// ---- END VEXCODE CONFIGURED DEVICES ----

// PORT 11 - 20 are on the left side
// PORT 1 - 10 are on the right side

#include "vex.h"
using namespace vex;

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 272 - 30;

// Convert degrees to radians
inline double to_radians(double degrees) {
  return degrees * (M_PI / 180.0);
}

// Draw a gear logo on the vex brain
void drawLogo(const int teeth=12, const int subtending_angle=20, const int minor_radius=80, const int major_radius=100) {

  // Prepare screen for drawing
  Brain.Screen.clearScreen();
  Brain.Screen.setPenColor(color::white);
  Brain.Screen.setPenWidth(3);
  Brain.Screen.setFont(monoL);

  // Draw inner circle of the gear
  Brain.Screen.drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, minor_radius);

  // Angle in degrees between teeth of gear
  const int angle_between_teeth = int(360 / teeth);

  // Array to store gear coordinates
  int gear_coords[361][2];

  // Loop over degrees in the gear circle
  for (int i = 0; i < 360; i++) {

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

  // Brain.Screen.setCursor(5, 5);
  Brain.Screen.printAt(SCREEN_WIDTH / 2 - 65, SCREEN_HEIGHT / 2 + 10, "ENGR CLUB");
  Brain.Screen.render();
}

void writeInfo(const int line, int value) {
  Brain.Screen.clearLine(line, color::black);
  Brain.Screen.setCursor(line, 1);
  Brain.Screen.print(value);
}

void joystickDebug(void) {
  writeInfo(1, Controller1.Axis3.value());
  writeInfo(2, Controller1.Axis4.value());
  Brain.Screen.render();
}

void identifyObjects(void) {
  writeInfo(1, robotEyes.objectCount);
  Brain.Screen.render();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Draws gear logo
  drawLogo();
  /*
  // creates a group of motors for each side (not needed since we currently have 1 motor each side)
  motor_group leftSideMotors = motor_group(leftFrontMotor, leftBackMotor);
  motor_group rightSideMotors = motor_group(rightFrontMotor, rightBackMotor);
  */
  bool running = true;

  // toggle practice
  bool toggleEnabled = false; // two-choice toggle, so we use bool
  bool buttonPressed = false; // logic variable

  // Creates a forever loop to keep the program running, until a specific condition is used to stop it.
  while(running)
  {
    // Identify objects
    // identifyObjects();

    // left analog stick uses axis 3 (up and down) and axis 4 (left and right)
    // right analog stick uses axis 2 (up and down) and axis 1 (left and right)
    // .position() method gives a result between -100 and 100
    // syntax: motor.spin(Direction, velocity, velocityUnits);

    // uses the left analog stick
    // up is forward (+), down is backward (-), right is rightward (+), left is leftward (-)
    leftWheels.spin(directionType::fwd, (Controller1.Axis3.position(pct) - Controller1.Axis4.position(pct)) / 2, pct);
    rightWheels.spin(directionType::fwd, (Controller1.Axis3.position(pct) + Controller1.Axis4.position(pct)) / 2, pct);

    // we want to adjust the speed for the arm and the chain motor.
    // Therefore we can set separate variables for this.
    int armMotorSpeed = 15;
    int chainMotorSpeed = 70;

    // set the armMotor and chainMotor to the trigger buttons.

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

    // toggle practice
    bool buttonA = Controller1.ButtonA.pressing();

    // toggle logic
    if(buttonA && !buttonPressed)
    {
      buttonPressed = true;
      toggleEnabled = !toggleEnabled;
    }
    else if (!buttonA)
    {
      buttonPressed = false;
    }

    // Code For toggle Enabled or Disabled
    if(toggleEnabled)
    {
      Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("Toggle On | Autonomous controls activitated");

      //Do another thing
    }
    else
    {
      Controller1.Screen.print("Toggle Off | Autonomous controls deactiviated");
      // do initial thing

    }

    

    wait(20,msec); // for refreshing the program.
  }
}
