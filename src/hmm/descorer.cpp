#include "main.h"

inline ez::Piston descorerPiston('E', true);

bool descorer_toggle_btn_pressed = false;
bool descorer_toggle_btn_pressing = false;

void descorer_opcontrol() {
  // descorer.button_toggle(master.get_digital_new_press(DIGITAL_A));
    descorer_toggle_btn_pressing = master.get_digital(DIGITAL_A);
    if (descorer_toggle_btn_pressing && !descorer_toggle_btn_pressed) {
      descorer.set(!descorer.get());
    }
    descorer_toggle_btn_pressed = descorer_toggle_btn_pressing;
}

bool Descorer::get() {
  return descorerPiston.get();
}

void Descorer::set(bool state) {
  descorerPiston.set(state);
}

void Descorer::open() {
  descorerPiston.set(true);
}

void Descorer::close() {
  descorerPiston.set(false);
}