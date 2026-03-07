#include "main.h"
#include "subsystems.hpp"

/*
 * AWP left: Loader first 
 *  1. loader, 
 *  2. long goal, 
 *  3. then center high goal
 */
void awp_left_1() {

  /// ### 1. Drive to loader ###
  /// ###
  raiser.lower(75);
  scraper.open();  
  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-89_deg, TURN_SPEED * 0.9);
  chassis.pid_wait();

  /// ### 2. Outtake from loader ###
  /// ###
  intaker.intake(100); // slower is more consistent when intaking from loader
  drive_to_distance(200, 500, 50);
  oscillate_between(200, 250, 35, 30, 2500);

  double distance_to_move_back_in = calc_distance_from_wall(560);
  chassis.pid_drive_set(-(distance_to_move_back_in), DRIVE_SPEED);
  scraper.close(); // close scraper earlier to prevent ball getting darg during turn
  chassis.pid_wait();
  intaker.stop();

  /// ### 3. Drive to long goal ###
  /// ###
  chassis.pid_turn_set(91_deg, TURN_SPEED * 0.8);
  chassis.pid_wait();
  raiser.raise(127);
  intaker.intake(127); // keep balls loose to prevent stuck
  pros::delay(500);  // Wait for raiser to raise
  chassis.pid_drive_set(15_in, 75, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1500);  // Wait for balls to outtake.
  intaker.stop();

  /// ### 4. Drive to intake balls at center ###
  /// ###
  chassis.pid_drive_set(-14_in, 75);
  chassis.pid_wait();
  raiser.lower(127);
  chassis.pid_turn_set(137_deg, TURN_SPEED * 0.8);
  chassis.pid_wait();
  intaker.intake(80);
  chassis.pid_drive_set(18_in, DRIVE_SPEED);
  raiser.lower(50);
  chassis.pid_wait();
  chassis.pid_drive_set(11_in, 30); // minimize 20 speed to drive 10_in
  chassis.pid_wait();
  intaker.intake(127);
  raiser.stop();

  /// ### 5. Outtake balls to center goal ###
  /// ###
  raiser.raise(127);
  chassis.pid_drive_set(19_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  // intaker.outtake(127);
  // pros::delay(1000);  // Wait for raiser to raise
  intaker.outtake(100);
  pros::delay(1000);  // Wait for raiser to raise
}