#include "subsystem.hpp"
#include <cstddef>

using namespace RPR;

Subsystem::Subsystem(){
  default_command = NULL;
}
Subsystem::~Subsystem(){
}
void Subsystem::set_default_command(Command* cmd) {
  default_command = cmd;
}
