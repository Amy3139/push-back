#include <sys/_intsup.h>
#include "main.h"
#include "subsystems.hpp"

///
/// skills_1 starting at Red right
void skills_2() {

  chassis.pid_drive_set(-30_in, 127, true);
  chassis.pid_wait();
}

