
#include <iostream>
#include "RPi-Robot.hpp"

int main(int argc, char** argv) {
  std::cout << "Starting Program" << std::endl;
  while(robot->is_running()){
    robot->execute();
  }
  delete robot;
  std::cout << "Ending Program" << std::endl;
}
