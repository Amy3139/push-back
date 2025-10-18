#include "main.h"
#include "subsystems.hpp"

///
// AWP right side
///
void skills_1() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

  chassis.pid_drive_set(-30_in, 127, true);
  chassis.pid_wait();
}