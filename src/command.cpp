#include "command.hpp"

using namespace RPR;

void Command::requires
(std::vector<Subsystem*> required_subsystems) {
  req_systems = required_subsystems;
}
std::vector<class Subsystem*>
Command::get_required_subsystems(void) {
  return req_systems;
}
