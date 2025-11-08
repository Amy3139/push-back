#include <sys/_intsup.h>
#include "main.h"
#include "subsystems.hpp"

///
/// skills_1 starting at Red right
void skills_1() {

  // #1. Get balls on right of center goal
  chassis.pid_drive_set(11_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(25);
  intaker.intake(127);
  chassis.pid_drive_set(8_in, 30, true);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 20, true);
  chassis.pid_wait();

  raiser.stop();

  // #2. Outtake balls into center goal
  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.raise(25);
  chassis.pid_drive_set(14_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  raiser.stop();
  intaker.outtake(80);
  pros::delay(2000);
  intaker.stop();

  // #3. Intake balls under long goal at right
  chassis.pid_drive_set(-22_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(38_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(25);
  intaker.intake(127);

  chassis.pid_drive_set(18_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(12_in, 20, true);
  chassis.pid_wait();
  intaker.stop();

  // #4. Outtake balls into long goal
  chassis.pid_drive_set(-26_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-11_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(18_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.raise(127);
  pros::delay(1000);  // Wait for raiser to raise

  chassis.pid_drive_set(9_in, 50, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(2000);

  // #5. Park
  chassis.pid_drive_set(-10_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  raiser.lower(55);
  pros::delay(1000);
  raiser.stop();

  chassis.pid_drive_set(-15_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(75_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-26_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-30_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

// void skills_1() {
//   chassis.pid_drive_set(-30_in, 127, true);
//   chassis.pid_wait();
// }