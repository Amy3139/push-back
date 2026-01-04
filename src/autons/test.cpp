#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/motors.h"

///
// Test autonomous
///
void test() {
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);

  raiser.lower(75);
  scraper.open();
  pros::delay(1000);

  chassis.pid_drive_set(6_in, 25, true);
  chassis.pid_wait();

  intaker.intake(100);
  chassis.drive_set(50, 50);
  pros::delay(200);
  raiser.stop();
  chassis.drive_set(10, 10);

  pros::delay(4000);
  intaker.stop();

  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_COAST);
}