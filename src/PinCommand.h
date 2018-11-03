#ifndef PIN_COMMAND_H
#define PIN_COMMAND_H

#include <Arduino.h>
#include "Timer.h"
#include "Command.h"


class PinCommand : public Command {
public:

    PinCommand(uint8_t _pin, uint8_t _direction, uint16_t _delay);
    void begin();
    void update();

private:
    uint8_t pin;
    uint8_t direction;
    Timer timer;

};
#endif
