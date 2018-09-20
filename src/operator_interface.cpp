#include "operator_interface.hpp"

using namespace RPR;

Operator_Interface::Operator_Interface() {

}
Operator_Interface::~Operator_Interface() {

}
void Operator_Interface::complete() {
  keyboard.process();
}
