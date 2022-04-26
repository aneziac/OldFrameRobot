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
  bool autoToggleEnabled = false; // two-choice toggle, so we use bool
  bool buttonPressed = false; // logic variable

  // Auto bools
  bool start = true;
  bool linedUp = false;
  bool nextToObject = false;

  // Creates a forever loop to keep the program running, until a specific condition is used to stop it.
  while (1)
  {
    bool buttonA = Controller1.ButtonA.pressing();

    // toggle logic
    if(buttonA && !buttonPressed)
    {
      buttonPressed = true;
      autoToggleEnabled = !autoToggleEnabled;
    }
    else if (!buttonA)
    {
      buttonPressed = false;
    }

    // Run auto if toggle on, otherwise use manual controls
    if (autoToggleEnabled) {
      autoRoutine(start, linedUp, nextToObject);
      if (start) {
        start = false;
      }
    } else {
      controls();
    }

    wait(20, msec); // for refreshing the program.
  }
}
