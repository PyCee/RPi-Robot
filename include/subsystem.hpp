#ifndef RPR_SUBSYSTEM_H
#define RPR_SUBSYSTEM_H

#include "command.hpp"

namespace RPR {
  class Subsystem {
  public:
    Subsystem();
    ~Subsystem();
    Command* get_default_command(void){return default_command;};
  protected:
    void set_default_command(Command*);
  private:
    Command* default_command;
  };
}

#endif /* RPR_SUBSYSTEM_H */
