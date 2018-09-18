#include "robot.hpp"
#include <iostream>
#include <algorithm>

using namespace RPR;

void Robot::execute(){
  std::vector<Command*>::iterator it = commands.begin();
  while(it != commands.end()){
    (*it)->execute();
    if((*it)->is_finished()){
      (*it)->end();
      it = commands.erase(it);
    } else {
      ++it;
    }
  }
  check_subsystem_defaults();
}
void Robot::add_command(Command* cmd) {
  // check cmd.reqs vs all active command reqs,
  //   delete any conflicting commands
  
  commands.push_back(cmd);
  cmd->init();
}

void Robot::check_subsystem_defaults(void)
{
  std::vector<Subsystem*>::iterator subsystem_it =
    subsystems.begin();
  while(subsystem_it != subsystems.end()) {
    std::vector<Command*>::iterator command_it =
      commands.begin();
    while(command_it != commands.end()) {
      std::vector<Subsystem*> req_systems =
	(*command_it)->get_required_subsystems();
      
      if(std::find(req_systems.begin(),
		   req_systems.end(),
		   *subsystem_it) != req_systems.end()) {
	// If a command has subsystem_it in it's requirements
	break;
      }
      ++command_it;
    }
    if(command_it == commands.end() &&
       (*subsystem_it)->get_default_command() != nullptr) {
      // Add subsystem default_command
      add_command((*subsystem_it)->get_default_command());
    }
    ++subsystem_it;
  }
}
void Robot::add_subsystem(Subsystem* sys) {
  subsystems.push_back(sys);
};
