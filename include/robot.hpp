#ifndef RPR_ROBOT_H
#define RPR_ROBOT_H

namespace RPR {
  class Robot {
  public:
    Robot(){running=true;};
    ~Robot(){};
    virtual void execute() = 0;
    bool is_running(void) {return running;}
  protected:
    bool running;
    /*
      Vector<Subsystems> subsystems;
      Operator_Interface oi;
     */
  };
}
#define SET_ROBOT(CLASS) RPR::Robot* robot = new CLASS

#endif /* RPR_ROBOT_H */
