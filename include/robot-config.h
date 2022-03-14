using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern signature robotEyes__COLORRED;
extern signature robotEyes__SIG_2;
extern signature robotEyes__COLORBLUE;
extern signature robotEyes__SIG_4;
extern signature robotEyes__SIG_5;
extern signature robotEyes__SIG_6;
extern signature robotEyes__SIG_7;
extern vision robotEyes;
extern motor armMotor;
extern motor chainMotor;
extern motor leftWheels;
extern motor rightWheels;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );