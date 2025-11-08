#include "main.h"
// #include "subsystems.hpp"

inline pros::Motor raiserMotor(13);

void raiser_opcontrol() {
  if (master.get_digital(DIGITAL_R1)) {
    raiser.raise(100);
  } 
  else if (master.get_digital(DIGITAL_R2)) {
    raiser.lower(100);
  } 
  else {
    raiser.stop();
  }
}

void Raiser::raise(int voltage) {
  raiserMotor.move(abs(voltage));
}

void Raiser::lower(int voltage) {
  raiserMotor.move(-abs(voltage));
}

void Raiser::set_brake_mode(pros::motor_brake_mode_e_t brake_type) {
  raiserMotor.set_brake_mode(brake_type);
}

void Raiser::stop() {
  raiserMotor.move(0);
}