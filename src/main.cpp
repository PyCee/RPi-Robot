
#include <iostream>
#include "RPi-Robot.hpp"

int main(int argc, char** argv) {
  std::cout << "Starting Program" << std::endl;
  int c = 0;
  while(robot->is_running()){
    robot->execute();
    c++;
  }
  delete robot;
  std::cout << "Ending Program" << std::endl;
}
