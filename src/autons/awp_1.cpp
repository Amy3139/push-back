#include <csignal>
#include "main.h"

/*
 * AWP: Loader first
 *  1. loader, 
 *  2. long goal, 
 *  3. then center goal
 */
void awp_1(bool run_right_side) {
  okapi::QLength initial_distance = run_right_side ? 30_in : 30_in;
  long negate_angle = run_right_side ? -1 : 1;
  double oscillation_speed = run_right_side ? 30 : 30;
  double oscillation_delta = run_right_side ? 35 : 25;

  /// ### 1. Drive to loader ###

  raiser.lower(75);
  scraper.open();  
  chassis.pid_drive_set(initial_distance, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg * negate_angle, TURN_SPEED * 0.9);
  chassis.pid_wait();

  /// ### 2. Outtake from loader ###

  intaker.intake(100); // slower is more consistent for intaking from loader
  // distance_with_oscillation(195, 3400, oscillation_speed, oscillation_delta);
  drive_to_distance(200, 500, 50);
  oscillate_between(200, 250, 30, 30, 2500);

  /*
   * When the robot can successfully intake all balls from loader and outtake into goal,
   * The move back value was: -12_in
   * The move forward value was: 15_in
   * And the distance from wall before moving back was around 259 mm
   * And the distance from wall after moving back was around 563 mm
  */

  double before_move_back = distanceSensor.get();

  double distance_to_move_back_in = calc_distance_from_wall(560);
  chassis.pid_drive_set(-(distance_to_move_back_in), DRIVE_SPEED, true);
  scraper.close(); // close scraper earlier to prevent ball getting darg during turn
  chassis.pid_wait();
  intaker.stop();
  // scraper.close(); 
  double after_move_back = distanceSensor.get();

  pros::lcd::print(5, "Before: %.1f, After: %.1f", before_move_back, after_move_back);

  /// ### 3. Drive to long goal ###

  chassis.pid_turn_set(90_deg * negate_angle, TURN_SPEED * 0.8);
  // intaker.intake(75); // keep balls loose
  chassis.pid_wait();
  raiser.raise(127);
  intaker.intake(127); // keep balls loose to prevent stuck
  pros::delay(500);  // Wait for raiser to raise
  chassis.pid_drive_set(15_in, 75, true);
  chassis.pid_wait();
  // intaker.outtake(127);
  // pros::delay(1500);  // Wait for balls to outtake.
  intaker.outtake(100); // start slower to increase chance of call staying in goal
  pros::delay(200);
  intaker.outtake(127);
  pros::delay(800);
  intaker.stop();

  /// ### 4. Drive to intake balls at center ###

  chassis.pid_drive_set(-12_in, 50, true);
  chassis.pid_wait();
  raiser.lower(127);
  chassis.pid_turn_set(138_deg * negate_angle, TURN_SPEED * 0.8);
  chassis.pid_wait();
  intaker.intake(80);
  chassis.pid_drive_set(16_in, DRIVE_SPEED, true);
  raiser.lower(50);
  chassis.pid_wait();

  chassis.pid_drive_set(11_in, 25); // minimize 20 speed to drive 10_in
  chassis.pid_wait();
  // intaker.stop();
  raiser.stop();

  /// ### 5. Outtake balls to center goal ###

  chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  // raiser.raise(25);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1800);
}