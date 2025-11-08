#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern ez::Piston scraperPiston;

void scraper_opcontrol();

class Scraper {
 public:
  bool get();
  void set(bool state);
  void open();
  void close();
};