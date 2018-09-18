#ifndef RPR_ROBO_H
#define RPR_ROBO_H

#include "RPi-Robot.hpp"
#include <iostream>
#include "beeper_subsystem.hpp"

namespace RPR_TEST{
  class Robo : public RPR::Robot {
  public:
    Robo();
    ~Robo(){};
  };
}
SET_ROBOT(RPR_TEST::Robo());
#endif /* RPR_ROBO_H */
