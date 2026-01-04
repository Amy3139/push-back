#include "main.h"
#include "subsystems.hpp"

///
// AWP left side: center goal then long goal (no loader)
///
void awp_left_2() {
  // #1. Get 3 balls
  chassis.pid_drive_set(11_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(25);
  intaker.intake(127);
  chassis.pid_drive_set(8_in, 30, true);
  chassis.pid_wait();
  chassis.pid_drive_set(9_in, 20, true);
  chassis.pid_wait();

  raiser.stop();

  // #2. Outtake 3 balls into center goal
  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();
  raiser.raise(100);
  chassis.pid_drive_set(16_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  raiser.stop();
  intaker.outtake(80);
  pros::delay(1200);
  intaker.stop();

  // #3. Intake 2 balls under long goal
  chassis.pid_drive_set(-23_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-38_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(50);
  intaker.intake(127);

  chassis.pid_drive_set(18_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(3_in, 30, true);
  chassis.pid_wait();
  pros::delay(1000);

  // #4. Outake balls into long goal
  chassis.pid_drive_set(-18_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  intaker.stop();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-11_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-100_deg, TURN_SPEED);
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
  pros::delay(1000); 
}

