#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor leftFrontMotor = motor(PORT11, ratio18_1, false);
motor leftBackMotor = motor(PORT12, ratio18_1, false);
motor rightFrontMotor = motor(PORT1, ratio18_1, false);
motor rightBackMotor = motor(PORT2, ratio18_1, false);
motor29 armMotor = motor29(Brain.ThreeWirePort.H, false);
motor29 clawMotor = motor29(Brain.ThreeWirePort.A, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}
