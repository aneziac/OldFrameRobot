/*
  debug.h
  Functions to help debug the robot
*/

#pragma once

#include "vex.h"
using namespace vex;


void writeInfo(const int line, int value) {
  Brain.Screen.clearLine(line, color::black);
  Brain.Screen.setCursor(line, 1);
  Brain.Screen.print(value);
}

void joystickDebug(void) {
  writeInfo(1, Controller1.Axis3.value());
  writeInfo(2, Controller1.Axis4.value());
  Brain.Screen.render();
}
