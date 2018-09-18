#ifndef RPR_BEEP_COMMAND_H
#define RPR_BEEP_COMMAND_H

#include "RPi-Robot.hpp"

namespace RPR_TEST {
  class Beep_Command : public RPR::Command {
  public:
    Beep_Command();
    ~Beep_Command();
    void init();
    void execute();
    bool is_finished();
    void end();
    void interupt();
  };
}

#endif /* RPR_BEEP_COMMAND_H */
