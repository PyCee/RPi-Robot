#include "oi/local_keyboard.hpp"
#include <iostream>
#include <ncurses.h>

using namespace RPR;

Local_Keyboard::Local_Keyboard() {
  initscr();
  noecho();
  cbreak();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);

  for(int i = 0; i < RPR_KEY_COUNT; ++i){
    key_down[i] = false;
  }
}
Local_Keyboard::~Local_Keyboard() {

}
void Local_Keyboard::process() {
  int character;
  if((character = getch()) != ERR){
    // TODO: handle key press
    // tell oi that key has been pressed so function may be called
  }
}
