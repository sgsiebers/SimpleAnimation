#include "FillCommand.h"


FillCommand::FillCommand(CRGB* _leds, uint16_t _length, CRGB _color, uint8_t _rate, Direction _direction) :
	LedCommand(_leds,_length),
	timer(Timer()),
	fillColor(_color),
	rate(_rate),
	direction(_direction),
	fillIndex(-1) {}



void FillCommand::begin(){
	DEBUG_PRINT("Begin Fill");
	done = false;
	timer.reset();
	fillIndex = (direction == Direction::FORWARD ?  0 : length-1);
}


void FillCommand::update(){
	uint16_t numToFill = min(timer.elapsedTime()/rate,length); //How many need to be filled
	int16_t stopPoint = (direction == Direction::FORWARD ? numToFill : length-numToFill-1);
	int16_t index = fillIndex;
	while(index != stopPoint){
		leds[index] = fillColor;
		if(direction == Direction::FORWARD){
			index++;
		}else{
			index--;
		}
	}
	done = (numToFill == length);
	#ifdef DEBUG
	if(done){
		DEBUG_PRINT("Fill Done");
	}
	#endif
}

