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

void autoRoutine(void) {

}
