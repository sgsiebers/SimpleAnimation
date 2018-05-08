#ifndef FADE_COMMAND_H
#define FADE_COMMAND_H


#include <Arduino.h>
#include "LedStrip.h"
#include "Timer.h"
#include "Command.h"


class FadeCommand : public Command {

  public:
    enum Direction {IN=0,OUT=1};
    
    FadeCommand();
    void init(LedStrip & _strip, CRGB _color, uint32_t _duration, Direction _direction);
    void begin();
    void update();

  private:
    LedStrip strip;
    CRGB color;
    uint32_t duration; //How long the fade effect should take (in ms)
    Direction direction;
    Timer timer;
    uint8_t currentScale;
};
#endif