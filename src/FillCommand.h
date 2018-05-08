#ifndef FILL_COMMAND_H
#define FILL_COMMAND_H

#include <Arduino.h>
#include "LedStrip.h"
#include "Timer.h"
#include "Command.h"

class FillCommand : public Command {

  public:
  
    enum Direction {FORWARD=0,REVERSE=1};

	FillCommand();
    void init(LedStrip & _strip, CRGB _color, uint8_t _rate, Direction _direction);
    void begin();
    void update();

  private:
    LedStrip strip;
    CRGB fillColor;
    uint8_t rate; // ms per pixel
    Direction direction;
    Timer timer;
    int16_t fillIndex;

};

#endif

