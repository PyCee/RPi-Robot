#include "beep_command.hpp"
#include <iostream>
#include <vector>
#include "robot_map.hpp"

using namespace RPR_TEST;
Beep_Command::Beep_Command() {
  std::vector<RPR::Subsystem*> req;
  req.push_back(&Robot_Map.beeper);
  requires(req);
}
Beep_Command::~Beep_Command() {

}
void Beep_Command::init() {
  //std::cout << "initing beep command" << std::endl;
}
void Beep_Command::execute() {
}
bool Beep_Command::is_finished() {
  return false;
}
void Beep_Command::end() {

}
void Beep_Command::interupt() {

}
