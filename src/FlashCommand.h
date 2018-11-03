#ifndef FLASHCOMMAND_H
#define FLASHCOMMAND_H



#include <Arduino.h>
#include "Timer.h"
#include "LedCommand.h"


class FlashCommand : public LedCommand {

  public:

    FlashCommand(CRGB* _leds, uint16_t _length, CRGB _color, uint16_t _duration, uint8_t _numFlashes );
    void begin();
    void update();

  private:
    CRGB color;
    uint16_t duration; //How long the flash effect should take (in ms)
    uint8_t numFlashes;
    Timer timer;
};

#endif
