#include "robot.hpp"
#include <iostream>
#include <algorithm>
#include <cstddef>

using namespace RPR;

void Robot::execute(){

  oi.complete();
  
  // Iterate over commands and execute
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
  //TODO::TEST
  
  // Check cmd.required subsystems vs all active command reqs,
  //   delete any conflicting commands
  std::vector<Subsystem*>req_subsystems =
    cmd->get_required_subsystems();
  std::vector<Subsystem*>::iterator req_subsystems_it =
    req_subsystems.begin();
  while(req_subsystems_it != req_subsystems.end()) {
    std::vector<Command*>::iterator command_it =
      commands.begin();
    while(command_it != commands.end()) {
      std::vector<Subsystem*> req_systems =
	(*command_it)->get_required_subsystems();
      if(std::find(req_systems.begin(),
		   req_systems.end(),
		   *req_subsystems_it) != req_systems.end()) {
	// If a command has req_subsystem_it in it's requirements
	std::cout << "subsystem already required, remove cmd"<<std::endl;
	//remove command
	break;
      }
      ++command_it;
    }
    ++req_subsystems_it;
  }
  
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
       (*subsystem_it)->get_default_command() != NULL) {
      // Add subsystem default_command
      add_command((*subsystem_it)->get_default_command());
    }
    ++subsystem_it;
  }
}
void Robot::add_subsystem(Subsystem* sys) {
  subsystems.push_back(sys);
};
