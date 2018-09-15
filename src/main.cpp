
#include <iostream>
#include "robot.hpp"

using namespace RPR;
extern Robot* robot;

int main(int argc, char** argv) {
  std::cout << "Starting Program" << std::endl;
  robot->execute();
  std::cout << "Ending Program" << std::endl;
}
