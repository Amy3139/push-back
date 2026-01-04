#include <csignal>
#include "main.h"

///
// AWP left side: loader then long goal
///
void awp_left_1() {
  // # 1. Drive to loader
  chassis.pid_drive_set(31_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-89_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(75);
  scraper.open();
  // pros::delay(1000);

  chassis.pid_drive_set(6_in, 25, true);
  chassis.pid_wait();

  // # 2. Intake balls from loader
  intaker.intake(80); // 80 is more consistent than 100
  chassis.drive_set(50, 50);
  pros::delay(100);
  // raiser.set_brake_mode(MOTOR_BRAKE_HOLD);
  // raiser.stop();
  raiser.lower(15);

  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
  // chassis.drive_set(10, 10);
  pros::delay(4000);
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  // raiser.set_brake_mode(MOTOR_BRAKE_COAST);

  intaker.stop();

  // # 3. Drive to long goal
  chassis.pid_drive_set(-15_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  scraper.close();
  chassis.pid_turn_set(89_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.raise(127);
  pros::delay(1000);  // Wait for raiser to raise

  chassis.pid_drive_set(15_in, 50, true);
  chassis.pid_wait();

}