#include "robo.hpp"
#include <iostream>
#include "robot_map.hpp"

using namespace RPR_TEST;

Robo::Robo(){
  add_subsystem(&Robot_Map.beeper);
}
