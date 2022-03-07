#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftFrontMotor = motor(PORT11, ratio18_1, false);
motor leftBackMotor = motor(PORT12, ratio18_1, false);
motor rightFrontMotor = motor(PORT1, ratio18_1, false);
motor rightBackMotor = motor(PORT2, ratio18_1, false);
motor29 armMotor = motor29(Brain.ThreeWirePort.H, false);
motor29 clawMotor = motor29(Brain.ThreeWirePort.A, false);
controller Controller1 = controller(primary);
/*vex-vision-config:begin*/
signature Vision1__COLORRED = signature (1, 7447, 9661, 8554, -1721, -629, -1176, 2.9, 0);
signature Vision1__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision1__COLORBLUE = signature (3, -3201, -2625, -2914, 5139, 6767, 5952, 2, 0);
vision Vision1 = vision (PORT15, 50, Vision1__COLORRED, Vision1__SIG_2, Vision1__COLORBLUE);
/*vex-vision-config:end*/

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}