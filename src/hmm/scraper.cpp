#include "main.h"

inline ez::Piston scraperPiston('D');

bool scraper_toggle_btn_pressed = false;
bool scraper_toggle_btn_pressing = false;

void scraper_opcontrol() {
  // scraper.button_toggle(master.get_digital_new_press(DIGITAL_X));
    scraper_toggle_btn_pressing = master.get_digital(DIGITAL_X);
    if (scraper_toggle_btn_pressing && !scraper_toggle_btn_pressed) {
      scraper.set(!scraper.get());
    }
    scraper_toggle_btn_pressed = scraper_toggle_btn_pressing;
}

bool Scraper::get() {
  return scraperPiston.get();
}

void Scraper::set(bool state) {
  scraperPiston.set(state);
}

void Scraper::open() {
  scraperPiston.set(true);
}

void Scraper::close() {
  scraperPiston.set(false);
}