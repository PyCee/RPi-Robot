#ifndef RPR_BEEPER_SUBSYSTEM_H
#define RPR_BEEPER_SUBSYSTEM_H

#include "RPi-Robot.hpp"
#include "beep_command.hpp"

namespace RPR_TEST {
  class Beeper_Subsystem : public RPR::Subsystem {
  public:
    Beeper_Subsystem();
    ~Beeper_Subsystem(){};
  private:
    Beep_Command default_cmd;
  };
}

#endif /* RPR_BEEPER_SUBSYSTEM_H */
