#ifndef FADE_COMMAND_H
#define FADE_COMMAND_H


#include <Arduino.h>
#include "Timer.h"
#include "LedCommand.h"


class FadeCommand : public LedCommand {

  public:
    enum Direction {IN=0,OUT=1};
    
    FadeCommand(CRGB* _leds, uint16_t _length, CRGB _color, uint16_t _duration, Direction _direction);
    void begin();
    void update();

  private:
    CRGB color;
    uint16_t duration; //How long the fade effect should take (in ms)
    Direction direction;
    Timer timer;
};
#endif
