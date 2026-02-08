#include "main.h"
#include "subsystems.hpp"

///
// AWP left side: center goal then long goal (no loader)
///
void awp_left_3() {
  scraper.open();
  raiser.lower(127);
  chassis.pid_drive_set(29_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-80_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  intaker.intake(100);
  raiser.lower(127);
  pros::delay(500);
  chassis.drive_set(30, 30);
  pros::delay(1000);
  chassis.drive_set(-30,-30);
  pros::delay(100);
  chassis.drive_set(30,30);
  pros::delay(400);
  chassis.drive_set(-30,-30);
  pros::delay(200);
  chassis.drive_set(30,30);
  pros::delay(400);
  chassis.drive_set(-30,-30);
  pros::delay(200);
  chassis.drive_set(30,30);
  pros::delay(400);
  chassis.drive_set(-30,-30);
  pros::delay(200);
  chassis.drive_set(30,30);
  intaker.stop();
  chassis.pid_drive_set(-15_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  scraper.close();
  raiser.raise(127);
  chassis.pid_turn_set(70_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(500);
  chassis.pid_drive_set(15_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  raiser.raise(127);
  pros::delay(300);
  intaker.outtake(127);
  pros::delay(1000);
  intaker.stop();
  chassis.pid_drive_set(-15_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  raiser.lower(127);
  chassis.pid_turn_set(120_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(500);
  intaker.intake(127);
  chassis.pid_drive_set(13_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  scraper.close();
  chassis.pid_drive_set(13_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  scraper.open();
  raiser.raise(127);
  pros::delay(500);
  raiser.stop();
  intaker.stop();
  chassis.pid_drive_set(5_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  intaker.outtake(127);
  pros::delay(1000);
  intaker.stop();
    

  



  pros::delay(1000);
}

