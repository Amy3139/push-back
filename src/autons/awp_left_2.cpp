#include "autons.hpp"
#include "main.h"
#include "subsystems.hpp"

///
// AWP left side: center goal then long goal (no loader)
///
void awp_left_2() {

  /// ### 1. Get center balls ###
  /// ###
    chassis.pid_drive_set(11_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    chassis.pid_turn_set(-45_deg, TURN_SPEED);
    chassis.pid_wait();

    raiser.lower(25);
    intaker.intake(100);
    chassis.pid_drive_set(8_in, 40);
    chassis.pid_wait();
    chassis.pid_drive_set(9_in, 30);
    chassis.pid_wait();
    raiser.stop();

  /// ### 2. Outtake 3 balls into center goal ###
    /// ###
    chassis.pid_turn_set(46_deg, TURN_SPEED);
    chassis.pid_wait();
    raiser.raise(127);
    pros::delay(70);
    chassis.pid_drive_set(17_in, DRIVE_SPEED);
    chassis.pid_wait();

    raiser.stop();
    intaker.outtake(100);
    pros::delay(1200);
    intaker.stop();

  /// ### 3. Outtake balls from loader ###
    /// ###
    chassis.pid_drive_set(-48_in, DRIVE_SPEED);
    raiser.lower(127);
    chassis.pid_wait();
    chassis.pid_turn_set(178_deg, TURN_SPEED);
    chassis.pid_wait();
    scraper.open();  
    raiser.lower(75);
    intaker.intake(127);
    drive_to_distance(200, 1000, 50);
    oscillate_between(200, 250, 40, 40, 2500);

  /// ### 4. Outtake to long goal ###
    /// ###
    double distance_to_move_back_in = calc_distance_from_wall(560);
    chassis.pid_drive_set(-(distance_to_move_back_in), DRIVE_SPEED, true);
    scraper.close(); // close scraper earlier to prevent ball getting darg during turn
    chassis.pid_wait();
    intaker.stop();
    // scraper.close();
    chassis.pid_turn_set(-2_deg, TURN_SPEED * 0.7);
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


