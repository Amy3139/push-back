#include <csignal>
#include "main.h"

/*
 * AWP left side: 
 *  1. loader, 
 *  2. long goal, 
 *  3. then center high goal
 */
void awp_left_1() {
  // # 1. Drive to loader
  // #
  raiser.lower(75);
  scraper.open();  chassis.pid_drive_set(31_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-89_deg, TURN_SPEED * 0.9);
  chassis.pid_wait();

  // # 2. Outtake from loader
  // #
  intaker.intake(127);
  distance_with_oscillation(190, 3500, 50, 35);
  chassis.pid_drive_set(-12_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  intaker.stop();
  scraper.close();

  // # 3. Drive to long goal
  // #
  chassis.pid_turn_set(90_deg, TURN_SPEED * 0.8);
  chassis.pid_wait();
  raiser.raise(127);
  pros::delay(1000);  // Wait for raiser to raise
  chassis.pid_drive_set(15_in, 75, true);
  chassis.pid_wait();
  intaker.outtake(127);
  // pros::delay(1800);  // Wait for balls to outtake.
  pros::delay(1500);  // Wait for balls to outtake. Save time
  intaker.stop();
return;
  // # 4. Drive to intake balls at center
  // #
  chassis.pid_drive_set(-10_in, 50, true);
  chassis.pid_wait();
  raiser.lower(127);
  chassis.pid_turn_set(140_deg, TURN_SPEED);
  chassis.pid_wait();
  intaker.intake(80);
  chassis.pid_drive_set(16_in, DRIVE_SPEED, true);
  raiser.lower(50);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 25, true);
  chassis.pid_wait();
  intaker.stop();

  // # 5. Outtake balls to center high goal
  // #
  raiser.raise(127);
  chassis.pid_drive_set(19_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1000);  // Wait for raiser to raise
}