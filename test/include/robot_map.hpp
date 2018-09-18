#ifndef RPR_ROBOT_MAP_H
#define RPR_ROBOT_MAP_H

#include "beeper_subsystem.hpp"
#include <iostream>

namespace RPR_TEST {
  struct Robot_Map_Type{
    Beeper_Subsystem beeper;
  };
}
extern struct RPR_TEST::Robot_Map_Type Robot_Map;
#endif /* RPR_ROBOT_MAP_H */
