#ifndef COMMAND_SEQ_H
#define COMMAND_SEQ_H

#include "Command.h"


class CommandSequence : public Command {

  public:
    CommandSequence(Command** _commands, uint8_t _size);
    void begin();
    void update();
  
  private:
    Command** commands;
    uint8_t size;
    uint8_t currentCommand;
};



#endif

