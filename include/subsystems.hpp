#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "hmm/descorer.hpp"
#include "hmm/intaker.hpp"
#include "hmm/raiser.hpp"
#include "hmm/scraper.hpp"
#include "okapi/impl/device/distanceSensor.hpp"

extern Drive chassis;
extern Descorer descorer;
extern Intaker intaker;
extern Raiser raiser;
extern Scraper scraper;

// Your motors, sensors, etc. should go here.  Below are examples
extern okapi::DistanceSensor distanceSensor;

// inline pros::Motor intake(1);
// inline pros::Motor raiser(13);
// inline ez::Piston scraper('D');
// inline pros::adi::DigitalIn limit_switch('A');