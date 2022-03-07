using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor leftFrontMotor;
extern motor leftBackMotor;
extern motor rightFrontMotor;
extern motor rightBackMotor;
extern motor29 armMotor;
extern motor29 clawMotor;
extern controller Controller1;
extern signature Vision1__COLORRED;
extern signature Vision1__SIG_2;
extern signature Vision1__COLORBLUE;
extern signature Vision1__SIG_4;
extern signature Vision1__SIG_5;
extern signature Vision1__SIG_6;
extern signature Vision1__SIG_7;
extern vision Vision1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );