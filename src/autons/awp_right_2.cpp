#include "main.h"
#include "subsystems.hpp"

///
// AWP right side: center goal then long goal (no loader)
///
void awp_right_2() {
  //
  // #1. Get 3 balls
  //
  chassis.pid_drive_set(11_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(25);
  intaker.intake(127);
  chassis.pid_drive_set(8_in, 40, true);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 30, true);
  chassis.pid_wait();
  // chassis.pid_drive_set(8_in, 20, true);
  // chassis.pid_wait();
  raiser.stop();

  //
  // #2. Outtake 3 balls into center goal
  //
  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  // raiser.raise(25);
  // raiser.stop();
  chassis.pid_drive_set(11_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  // raiser.lower(25);
  // intaker.outtake(70);
  // pros::delay(500);
  intaker.outtake(127);
  pros::delay(1000);
  intaker.stop();

  //
  // #3. Outtake balls from loader
  //
  chassis.pid_drive_set(-43_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-180_deg, TURN_SPEED * 0.8);
  chassis.pid_wait();
  scraper.open();  
  raiser.lower(75);
  intaker.intake(127);
  // distance_with_oscillation(195, 3600, 50, 40);
  drive_to_distance(200, 500, 50);
  oscillate_between(200, 250, 30, 30, 2500);

  //
  // # 4. Outtake to long goal
  // #
  static const double distance_from_wall_to_turn = 560;
  double distance_from_wall = distanceSensor.get();
  double distance_to_move_back_mm = (distance_from_wall_to_turn - distance_from_wall);
  double distance_to_move_back_in = distance_to_move_back_mm / 25.4;

  double before_move_back = distanceSensor.get();

  chassis.pid_drive_set(-(distance_to_move_back_in), DRIVE_SPEED, true);
  chassis.pid_wait();
  intaker.stop();
  scraper.close();
  chassis.pid_turn_set(2_deg, TURN_SPEED * 0.8);
  chassis.pid_wait();

  raiser.raise(127);
  pros::delay(500);  // Wait for raiser to raise
  chassis.pid_drive_set(15_in, 75, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1800);  // Wait for balls to outtake. Save time
  intaker.stop();
}
