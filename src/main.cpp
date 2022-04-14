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

  // Booleans
  bool running = true;
  bool autoOn = false;

  // toggle practice
  bool toggleEnabled = false; // two-choice toggle, so we use bool
  bool buttonPressed = false; // logic variable

  // Creates a forever loop to keep the program running, until a specific condition is used to stop it.
  while(running)
  {
    if (autoOn) {
      autoRoutine();
    } else {
      controls();
    }

    wait(20, msec); // for refreshing the program.
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

      // camera image is 316 pixels wide, so the center is 316/2
      int screen_middle_x = 316 / 2;
      bool linedUp = false;

      while(!linedUp)
      {
        robotEyes.takeSnapshot(robotEyes__COLORRED);
        if(robotEyes.objectCount > 0)
        {
          if (robotEyes.largestObject.centerX < screen_middle_x - 5)
          {
            // turn left
          } else if (robotEyes.largestObject.centerX > screen_middle_x + 5) {
            // turn right
          }
        }
      }
      // move toward block and stop next to it
    }
    else
    {
      Controller1.Screen.print("Toggle Off | Autonomous controls deactiviated");
      // do initial thing

    }

    wait(20,msec); // for refreshing the program.
  }
}
