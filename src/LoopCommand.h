#ifndef LOOP_COMMAND_H
#define LOOP_COMMAND_H

#include <Arduino.h>
#include "LedStrip.h"
#include "Command.h"

class LoopCommand : public Command {

  public:
  
    static const uint16_t INFINITE = 0;
  
	LoopCommand();
    void init(const uint16_t _iters, Command* _command);
    void begin();
    void update();

  private:
    uint16_t loopIters;
    bool isInfinite;
    Command* command;
    uint16_t loopCount;
    
};

#endif