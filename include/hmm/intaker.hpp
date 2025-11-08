#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern pros::Motor intakerMotor;

void intaker_opcontrol();

class Intaker {
 public:
  void intake(int voltage);
  void outtake(int voltage);
  void stop();
};