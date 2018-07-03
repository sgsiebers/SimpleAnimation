#ifndef SOUND_COMMAND_H
#define SOUND_COMMAND_H

#include <Arduino.h>
#include "Command.h"
#include "Timer.h"

#define SOUND_PIN_HOLD_TIME 125

/*
 * Used with Adafruit Audio FX Sound Board to trigger sounds effects via Digital IO pin
 * (@see https://learn.adafruit.com/adafruit-audio-fx-sound-board/overview)
 */
class SoundCommand : public Command {

  public:
    SoundCommand(const uint8_t _pin, const uint16_t _duration);
	void begin();
    void update();

  private:
    const uint8_t pin;
    bool pinActive;
    Timer playTimer;
  
};


#endif
