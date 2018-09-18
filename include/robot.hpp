#ifndef RPR_ROBOT_H
#define RPR_ROBOT_H

#include "subsystem.hpp"
#include "command.hpp"
#include <vector>

namespace RPR {
  class Robot {
  public:
    Robot(){running=true;};
    ~Robot(){};
    void execute();
    bool is_running(void) {return running;}
    void add_command(Command*);
  protected:
    void add_subsystem(Subsystem*);
    bool running;
    std::vector<Subsystem*> subsystems;
    std::vector<Command*> commands;
    /*
      Operator_Interface oi;
    */
  private:
    void check_subsystem_defaults(void);
  };
}
#define SET_ROBOT(CLASS) RPR::Robot* robot = new CLASS

#endif /* RPR_ROBOT_H */
