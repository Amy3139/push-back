#include "main.h"
// #include "subsystems.hpp"

inline pros::Motor intakerMotor(-1);

void intaker_opcontrol() {
  if (master.get_digital(DIGITAL_L1)) {
    intaker.intake(127);
  } 
  else if (master.get_digital(DIGITAL_L2)) {
    intaker.outtake(127);
  } 
  else {
    intaker.stop();
  }
}

void Intaker::intake(int voltage) {
  intakerMotor.move(abs(voltage));
}

void Intaker::outtake(int voltage) {
  intakerMotor.move(-abs(voltage));
}

void Intaker::stop() {
  intakerMotor.move(0);
}