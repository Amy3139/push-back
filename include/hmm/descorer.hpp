#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern ez::Piston descorerPiston;

void descorer_opcontrol();

class Descorer {
 public:
  bool get();
  void set(bool state);
  void open();
  void close();
};