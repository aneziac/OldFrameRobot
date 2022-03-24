#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
/*vex-vision-config:begin*/
signature robotEyes__COLORRED = signature (1, 7447, 9661, 8554, -1721, -629, -1176, 2.9, 0);
signature robotEyes__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 3, 0);
signature robotEyes__COLORBLUE = signature (3, -3201, -2625, -2914, 5139, 6767, 5952, 2, 0);
vision robotEyes = vision (PORT10, 50, robotEyes__COLORRED, robotEyes__SIG_2, robotEyes__COLORBLUE);
/*vex-vision-config:end*/
motor armMotor = motor(PORT16, ratio18_1, false);
motor chainMotor = motor(PORT17, ratio18_1, false);
motor leftWheels = motor(PORT1, ratio18_1, false);
motor rightWheels = motor(PORT11, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonL1/ButtonL2 status to control armMotor
      if (Controller1.ButtonL1.pressing()) {
        armMotor.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        armMotor.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        armMotor.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }
      // check the ButtonR1/ButtonR2 status to control chainMotor
      if (Controller1.ButtonR1.pressing()) {
        chainMotor.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        chainMotor.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        chainMotor.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1RightShoulderControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}