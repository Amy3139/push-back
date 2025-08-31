#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor intake(1);
inline pros::Motor raiser(13);
inline ez::Piston scraper('D');
// inline pros::adi::DigitalIn limit_switch('A');