/*
  auto.h
  Code for operating the robot autonomously
*/

#include "vex.h"
#include "debug.h"
using namespace vex;


// Use computer vision to identify objects
void identifyObjects(void) {
  writeInfo(1, robotEyes.objectCount);
  Brain.Screen.render();
}

// turn the robot left a little bit some number of times
void turnLeft(const int times) {
  for (int i = 0; i < times; i++) {
    leftWheels.spin(directionType::rev);
    rightWheels.spin(directionType::fwd);
  }
}

// turn the robot right a little bit some number of times
void turnRight(const int times) {
  for (int i = 0; i < times; i++) {
    leftWheels.spin(directionType::fwd);
    rightWheels.spin(directionType::rev);
  }
}

// moves the robot forward some number of times
void driveForward(const int times) {
  for (int i = 0; i < times; i++) {
    leftWheels.spin(directionType::fwd);
    rightWheels.spin(directionType::fwd);
  }
}

void autoRoutine(bool& linedUp, bool& nextToObject) {  // note these are references
  /*
  Simple autonomous routine

  1. Robot turns until it identifies a red object
  2. When it is fully facing the red object, it drives forward until it is very close to the object
  */

  // camera image is 316 pixels wide, so the center is 316/2
  const int screen_middle_x = 316 / 2;

  while(!linedUp)
  {
    robotEyes.takeSnapshot(robotEyes__COLORRED);
    if(robotEyes.objectCount > 0)
    {
      if (robotEyes.largestObject.centerX < screen_middle_x - 5)
      {
        turnLeft(2);
      } else if (robotEyes.largestObject.centerX > screen_middle_x + 5) {
        turnRight(2);
      } else {
        linedUp = true;
      }
    } else {
      turnRight(5);
    }
  }

  // At this point object has been identified and is in center of camera's vision
  while (!nextToObject) {
    robotEyes.takeSnapshot(robotEyes__COLORRED);
    if (robotEyes.largestObject.width < 200) {  // objects get bigger as they get closer
      driveForward(2);
    } else {
      nextToObject = true;
    }
  }
}
