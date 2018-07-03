#ifndef LED_COMMAND_H
#define LED_COMMAND_H

#include "Command.h"
#include "FastLED.h"


class LedCommand : public Command {


public:
	LedCommand(CRGB* _leds, uint16_t _length);

protected:
	CRGB* leds;
	uint16_t length;

};
#endif
