#ifndef RPR_COMMAND_H
#define RPR_COMMAND_H

#include <vector>

namespace RPR{
  class Command {
  public:
    Command(){};
    ~Command(){};
    virtual void init() = 0;
    virtual void execute() = 0;
    virtual bool is_finished() = 0;
    virtual void end() = 0;
    virtual void interupt() = 0;
    void requires(std::vector<class Subsystem*>);
    std::vector<class Subsystem*> get_required_subsystems(void);
  private:
    std::vector<class Subsystem*> req_systems;
  };
}

#endif /* RPR_COMMAND_H */
