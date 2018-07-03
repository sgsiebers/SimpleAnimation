#ifndef LOOP_COMMAND_H
#define LOOP_COMMAND_H

#include <Arduino.h>
#include "Command.h"

class LoopCommand : public Command {

  public:
  
    static const uint16_t INFINITE = 0;
  
	LoopCommand(const uint16_t _numIterations, Command* _command);
    void begin();
    void update();

  private:
    uint16_t numIterations;
    uint16_t currentCount;
    Command* command;
    
};

#endif
