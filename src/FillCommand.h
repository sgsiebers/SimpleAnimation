#ifndef FILL_COMMAND_H
#define FILL_COMMAND_H

#include <Arduino.h>
#include "Timer.h"
#include "LedCommand.h"

class FillCommand : public LedCommand {

  public:
  
    enum Direction {FORWARD=0,REVERSE=1};

	FillCommand(CRGB* _leds, uint16_t _length, CRGB _color, uint8_t _rate, Direction _direction);
    void begin();
    void update();

  private:
    Timer timer;
    CRGB fillColor;
    uint8_t rate; // ms per pixel
    Direction direction;
    int16_t fillIndex;

};

#endif

