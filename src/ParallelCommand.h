#ifndef PARALLEL_CMD_H
#define PARALLEL_CMD_H

#include "Command.h"


class ParallelCommand : public Command {

  public:
    ParallelCommand(Command** _commands, uint8_t _size);
    void begin();
    void update();
  
  private:
    Command** commands;
    uint8_t size;
};



#endif

