#include "main.h"
#include "subsystems.hpp"

///
// AWP right side
///
void awp_right_2() {
  // #1. Get 3 balls
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

  // #2. Outtake 3 balls into center goal
  
  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.raise(25);
  chassis.pid_drive_set(14_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  raiser.stop();
  intaker.outtake(80);
  pros::delay(1500);
  intaker.stop();

  // #3. Intake 2 balls under long goal
  chassis.pid_drive_set(-22_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(38_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(25);
  intaker.intake(127);

  chassis.pid_drive_set(18_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(6_in, 25, true);
  chassis.pid_wait();
  intaker.stop();

  // #4. Outake balls into long goal
  chassis.pid_drive_set(-20_in, DRIVE_SPEED, true);
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

  chassis.pid_drive_set(10_in, 50, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(2000);
}