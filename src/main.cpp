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
#include "logo.h"
#include "auto.h"
#include "debug.h"
#include "controls.h"
using namespace vex;


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Draws gear logo
  drawLogo();

  // Auto toggle
  bool autoToggleEnabled = false; // whether the auto toggle is on or off
  bool buttonPressed = false; // whether the A button is being pressed

  // Auto bools
  bool linedUp = false;  // whether the robot is pointing directly towards the object
  bool nextToObject = false;  // whether the robot is right next to the object

  // Creates a forever loop to keep the program running, until a specific condition is used to stop it.
  while (1)
  {
    bool buttonA = Controller1.ButtonA.pressing();

    // toggle logic
    if(buttonA && !buttonPressed)
    {
      buttonPressed = true;
      autoToggleEnabled = !autoToggleEnabled;

      // Put toggle information on the controller
      if (autoToggleEnabled) {
        Controller1.Screen.clearScreen();
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print("Toggle On | Autonomous controls activitated");
      } else {
        Controller1.Screen.clearScreen();
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print("Toggle Off | Autonomous controls deactivitated");
      }
    }
    else if (!buttonA)
    {
      buttonPressed = false;
    }

    // Run auto if toggle on, otherwise use manual controls
    if (autoToggleEnabled) {
      autoRoutine(linedUp, nextToObject);
    } else {
      controls();
    }

    wait(20, msec); // for refreshing the program.
  }
}
