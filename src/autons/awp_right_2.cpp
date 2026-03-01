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
  chassis.pid_drive_set(17_in, 30, true);
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
  distance_with_oscillation(195, 3600, 50, 40);

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
  pros::delay(1000);  // Wait for raiser to raise
  chassis.pid_drive_set(14_in, 75, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1500);  // Wait for balls to outtake. Save time
  intaker.stop();
}

///
// AWP right side: center goal then long goal (no loader)
///
void awp_right_2_old() {
  // #1. Get 3 balls
  chassis.pid_drive_set(11_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.lower(25);
  intaker.intake(127);
  chassis.pid_drive_set(8_in, 30, true);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 20, true);
  chassis.pid_wait();

  raiser.stop();

  // #2. Outtake 3 balls into center goal
  
  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  raiser.raise(25);
  chassis.pid_drive_set(14_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  raiser.stop();
  intaker.outtake(80);
  pros::delay(1500);
  intaker.stop();

  // #3. Intake 2 balls under long goal
  chassis.pid_drive_set(-22_in, DRIVE_SPEED, true);
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

  // #4. Outake balls into long goal
  chassis.pid_drive_set(-20_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-11_in, DRIVE_SPEED, true);
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
  pros::delay(2000);
}