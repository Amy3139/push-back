#include "main.h"
#include "subsystems.hpp"

///
// AWP right side: center goal then long goal (no loader)
///
void awp_right_2() {

  /// ### 1. Get 3 balls ###
  /// ###
  chassis.pid_drive_set(11_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(25);
  intaker.intake(100);
  chassis.pid_drive_set(8_in, 40, true);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 30, true);
  chassis.pid_wait();
  raiser.stop();

  /// ### 2. Outtake 3 balls into center goal ###
  /// ###
  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(11_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  intaker.outtake(100);
  pros::delay(200);
  intaker.outtake(127);
  pros::delay(800);
  intaker.stop();

  /// ### 3. Outtake balls from loader ###
  /// ###
  chassis.pid_drive_set(-42_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-180_deg, TURN_SPEED * 0.8);
  chassis.pid_wait();
  scraper.open();  
  raiser.lower(75);
  intaker.intake(127);
  // distance_with_oscillation(195, 3600, 50, 40);
  drive_to_distance(200, 500, 50);
  oscillate_between(200, 250, 30, 30, 2500);

  /// ### 4. Outtake to long goal ###
  /// ###
  double distance_to_move_back_in = calc_distance_from_wall(560);
  chassis.pid_drive_set(-(distance_to_move_back_in), DRIVE_SPEED, true);
  scraper.close(); // close scraper earlier to prevent ball getting darg during turn
  chassis.pid_wait();
  intaker.stop();
  // scraper.close();
  chassis.pid_turn_set(2_deg, TURN_SPEED * 0.8);
  chassis.pid_wait();

  raiser.raise(127);
  intaker.intake(127); // keep balls loose to prevent stuck
  pros::delay(500);  // Wait for raiser to raise
  chassis.pid_drive_set(15_in, 75, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1500);  // Wait for balls to outtake.
  intaker.stop();
}
