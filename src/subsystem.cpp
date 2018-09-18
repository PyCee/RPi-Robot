#include "subsystem.hpp"

using namespace RPR;

Subsystem::Subsystem(){
  default_command = nullptr;
}
Subsystem::~Subsystem(){
}
void Subsystem::set_default_command(Command* cmd) {
  default_command = cmd;
}
