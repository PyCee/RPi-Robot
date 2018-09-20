#ifndef RPR_LOCAL_KEYBOARD_H
#define RPR_LOCAL_KEYBOARD_H

#define RPR_KEY_COUNT 2<<9

namespace RPR {
  class Local_Keyboard {
  public:
    Local_Keyboard();
    ~Local_Keyboard();
    void process();
  private:
    bool key_down[RPR_KEY_COUNT];
  };
}

#endif /* RPR_LOCAL_KEYBOARD_H */
