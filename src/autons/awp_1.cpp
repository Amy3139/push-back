#include <csignal>
#include "main.h"

/*
 * AWP: 
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

  intaker.intake(127);
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

  static const double distance_from_wall_to_turn = 560;
  double distance_from_wall = distanceSensor.get();
  double distance_to_move_back_mm = (distance_from_wall_to_turn - distance_from_wall);
  double distance_to_move_back_in = distance_to_move_back_mm / 25.4;

  double before_move_back = distanceSensor.get();

  // chassis.pid_drive_set(-12_in, DRIVE_SPEED, true);
  chassis.pid_drive_set(-(distance_to_move_back_in), DRIVE_SPEED, true);
  chassis.pid_wait();
  intaker.stop();
  scraper.close();

  double after_move_back = distanceSensor.get();

  pros::lcd::print(5, "Before: %.1f, After: %.1f", before_move_back, after_move_back);

  /// ### 3. Drive to long goal ###

  chassis.pid_turn_set(90_deg * negate_angle, TURN_SPEED * 0.8);
  chassis.pid_wait();
  raiser.raise(127);
  pros::delay(600);  // Wait for raiser to raise
  chassis.pid_drive_set(15_in, 75, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1500);  // Wait for balls to outtake.
  intaker.stop();

  /// ### 4. Drive to intake balls at center ###

  chassis.pid_drive_set(-12_in, 50, true);
  chassis.pid_wait();
  raiser.lower(127);
  chassis.pid_turn_set(138_deg * negate_angle, TURN_SPEED * 0.8);
  chassis.pid_wait();
  intaker.intake(100);
  chassis.pid_drive_set(17_in, DRIVE_SPEED, true);
  raiser.lower(50);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, 25); // minimize 20 speed to drive 10_in
  chassis.pid_wait();
  // intaker.stop();
  raiser.stop();

  /// ### 5. Outtake balls to center high goal ###

  chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  // raiser.raise(25);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1800);
}