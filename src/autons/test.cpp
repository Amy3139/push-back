#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/motors.h"

///
// Test autonomous
///
void test_outtake_from_loader_with_distance_sensor() {
  scraper.open();
  pros::delay(500);
  raiser.lower(75);
  intaker.intake(127); // 80 is more consistent than 100
  // chassis.drive_set(50, 50);
  // pros::delay(500);

  drive_to_distance(195, 3000, 30);
return;

  distance_with_oscillation(195, 3400, 30);
  chassis.pid_drive_set(-12_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  intaker.stop();
  scraper.close();
}

///
// Test autonomous
///
void test_outtake_from_loader_1() {
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

void test() {
  test_outtake_from_loader_with_distance_sensor();  
}