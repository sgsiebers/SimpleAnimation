#include "PinCommand.h"

PinCommand::PinCommand(uint8_t _pin, uint8_t _direction, uint16_t _delay):
	pin( _pin),
	direction( _direction),
	timer(Timer(_delay)) {}

void PinCommand::begin(){
    DEBUG_PRINT("Begin PinCommand");
    done = false;
    timer.reset();
}

void PinCommand::update(){
	if(!done && timer.expired()){
	    digitalWrite(pin,direction);
	    done = true;
	    DEBUG_PRINT("PinCommand Done");
	}
}
