#include <sys/_intsup.h>
#include "main.h"
#include "subsystems.hpp"

///
/// skills_3 starting at Red right the same as awp_right_1
/// i.e. on right of red parking lot.


void part1() {
  bool run_right_side = true;
  okapi::QLength initial_distance = 30_in; // previous value
  long negate_angle = -1;
  double oscillation_speed = 35;
  double oscillation_delta = 35;

  // # 1. Drive to loader
  // #
  raiser.lower(75);
  scraper.open();  chassis.pid_drive_set(initial_distance, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-89_deg * negate_angle, TURN_SPEED * 0.9);
  chassis.pid_wait();

  // # 2. Outtake from loader
  // #
  intaker.intake(127);
  // distance_with_oscillation(190, 3400, oscillation_speed, oscillation_delta);
  distance_with_oscillation(190, 7000, oscillation_speed, oscillation_delta);
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

  // # 3. Drive to long goal
  // #
  chassis.pid_turn_set(90_deg * negate_angle, TURN_SPEED * 0.8);
  chassis.pid_wait();
  raiser.raise(127);
  pros::delay(1000);  // Wait for raiser to raise
  chassis.pid_drive_set(15_in, 75, true);
  chassis.pid_wait();
  intaker.outtake(127);
  // pros::delay(1500);  // Wait for balls to outtake. Save time
  pros::delay(2000);  // Wait for balls to outtake. Save time
  intaker.stop();

  // # 4. Drive to intake balls at center
  // #
  // chassis.pid_drive_set(-12_in, 50, true);
  chassis.pid_drive_set(-10_in, 50, true);
  chassis.pid_wait();
  raiser.lower(127);
  // chassis.pid_turn_set(140_deg * negate_angle, TURN_SPEED);
  chassis.pid_turn_set(142_deg * negate_angle, TURN_SPEED);
  chassis.pid_wait();
  intaker.intake(127);
  // chassis.pid_drive_set(17_in, DRIVE_SPEED, true);
  chassis.pid_drive_set(15_in, DRIVE_SPEED, true);
  raiser.lower(50);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, 20); // minimize 20 speed to drive 10_in
  chassis.pid_wait();
  intaker.stop();
  raiser.stop();

  // # 5. Outtake balls to center high goal
  // #
  chassis.pid_drive_set(15_in, DRIVE_SPEED, true);
  raiser.raise(15);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1000);  // Wait for raiser to raise
}

void skills_3() {
  part1();
}

