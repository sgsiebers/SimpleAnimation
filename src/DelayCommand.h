#ifndef DELAY_CMD_H
#define DELAY_CMD_H



#include <Arduino.h>
#include "Timer.h"
#include "Command.h"


class DelayCommand : public Command {

public:
    DelayCommand();
    void init(uint32_t _duration);
    void begin();
    void update();
    
private:
    Timer timer;

};
#endif