#include "main.h"
#include "subsystems.hpp"

///
/// skills_1 starting at Red right
void skills_1() {
  // # 1: Drive forward to the first platform
  chassis.pid_drive_set(30_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

// void skills_1() {
//   chassis.pid_drive_set(-30_in, 127, true);
//   chassis.pid_wait();
// }