#include "beeper_subsystem.hpp"

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
using namespace RPR_TEST;

Beeper_Subsystem::Beeper_Subsystem() {
  set_default_command(&default_cmd);
}
