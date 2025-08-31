#include "main.h"
#include "subsystems.hpp"

///
// AWP right side
///
void awp_right_2() {
  // chassis.pid_turn_set(45_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_turn_set(40_deg, 25);
  // chassis.pid_wait();

  // return;

  chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(43_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.move(-25);
  intake.move(-127);
  chassis.pid_drive_set(18_in, 30, true);
  chassis.pid_wait();

    // // TODO: scrape blocks from loader after scraper improved
  raiser.move(0);

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  raiser.move(0);
  intake.move(80);
  pros::delay(1000);
  intake.move(0);

  chassis.pid_drive_set(-20_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(38_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(18_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  raiser.move(-25);
  intake.move(-127);
  chassis.pid_drive_set(6_in, 25, true);
  chassis.pid_wait();
  intake.move(0);

  // chassis.pid_drive_set(-36_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(28_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  chassis.pid_drive_set(-20_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-10_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(18_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.move(127);
  pros::delay(1000);  // Wait for raiser to raise

  chassis.pid_drive_set(8_in, 50, true);
  chassis.pid_wait();
  intake.move(127);
  pros::delay(1000);  // Wait for raiser to raise
}