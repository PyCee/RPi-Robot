#ifndef RPR_ROBO_H
#define RPR_ROBO_H

#include "robot.hpp"
#include <iostream>

namespace RPR{
  class Robo : public Robot {
  public:
    Robo(){};
    ~Robo(){};
    void execute() {std::cout << "Custom Execute" << std::endl;};
  };
}
SET_ROBOT(RPR::Robo());
#endif /* RPR_ROBO_H */
