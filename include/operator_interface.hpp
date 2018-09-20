#ifndef RPR_OPERATOR_INTERFACE_H
#define RPR_OPERATOR_INTERFACE_H

#include "oi/local_keyboard.hpp"

namespace RPR {
  class Operator_Interface {
  public:
    Operator_Interface();
    ~Operator_Interface();
    void complete();
  protected:
    Local_Keyboard keyboard;
  private:
    enum Button_Actions {
      When_Pressed,
      When_Released,
      While_Held
    };
    
  };
}

#endif /* RPR_OPERATOR_INTERFACE_H */
