#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern pros::Motor raiserMotor;

void raiser_opcontrol();
    
class Raiser {
 public:
  void raise(int voltage);
  void lower(int voltage);
  void set_brake_mode(pros::motor_brake_mode_e_t brake_type);
  void stop();
};