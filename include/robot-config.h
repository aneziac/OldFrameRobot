using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftFrontMotor;
extern motor leftBackMotor;
extern motor rightFrontMotor;
extern motor rightBackMotor;
extern motor29 armMotor;
extern motor29 clawMotor;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );