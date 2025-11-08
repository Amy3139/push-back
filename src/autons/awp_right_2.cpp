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
  // std::uint32_t start_time_ms = pros::millis();

  chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(43_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(25);
  intaker.intake(127);
  chassis.pid_drive_set(9_in, 30, true);
  chassis.pid_wait();
  chassis.pid_drive_set(9_in, 20, true);
  chassis.pid_wait();
  // chassis.pid_drive_set(6_in, 30, true);
  // chassis.pid_wait();

    // // TODO: scrape blocks from loader after scraper improved
  raiser.stop();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  raiser.stop();
  intaker.outtake(80);
  pros::delay(1000);
  intaker.stop();

  // std::uint32_t elapsed_time_ms = pros::millis() - start_time_ms;
  // printf("Mid: elapsed time: %u ms\n", elapsed_time_ms);
  // pros::lcd::print(6, "Mid: elapsed time: %d ms", elapsed_time_ms);

  chassis.pid_drive_set(-20_in, DRIVE_SPEED, true);
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

  raiser.raise(127);
  pros::delay(1000);  // Wait for raiser to raise

  chassis.pid_drive_set(10_in, 50, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1000); 

  // elapsed_time_ms = pros::millis() - start_time_ms;
  // printf("End: elapsed time: %u ms\n", elapsed_time_ms);
  // pros::lcd::print(7, "End: elapsed time: %d ms", elapsed_time_ms);
}