#ifndef DELAY_CMD_H
#define DELAY_CMD_H

#include "Command.h"
#include "Timer.h"


class DelayCommand : public Command {

public:
    DelayCommand(uint16_t _duration);
    void begin();
    void update();
    
private:
    Timer timer;

};
#endif
