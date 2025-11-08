#include "main.h"
#include "subsystems.hpp"

///
// AWP right side
///
void awp_right_1() {
  chassis.pid_drive_set(30_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  scraper.open();
  pros::delay(ez::util::DELAY_TIME);

  chassis.pid_drive_set(2_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  // TODO: scrape blocks from loader after scraper improved
  pros::delay(3000); 

  chassis.pid_drive_set(-12_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  scraper.close();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  // TODO: improve after raiser has PID (required rotation sensor)
  raiser.raise(100);
  pros::delay(1000);  // Wait for raiser to raise

  chassis.pid_drive_set(9_in, 80, true);
  chassis.pid_wait();

  intaker.outtake(127);
  pros::delay(1000);  // Wait for intaker to pick up blocks

  chassis.pid_drive_set(-10_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  raiser.raise(127);
  pros::delay(500);  // Wait for raiser to raise

  chassis.pid_turn_set(-150_deg, TURN_SPEED);
  chassis.pid_wait();

  intaker.intake(127);
  chassis.pid_drive_set(18_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(2_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-160_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(5_in, 50, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-140_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(14_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  intaker.outtake(127);
  pros::delay(1000);  // Wait for intakerMotor to pick up blocks
  intaker.stop();
}