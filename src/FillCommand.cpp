#include "FillCommand.h"


FillCommand::FillCommand() : timer(Timer()){}

void FillCommand::init(LedStrip& _strip, CRGB _color, uint8_t _rate, Direction _direction){
	strip=_strip;
	fillColor=_color;
	rate=_rate;
	direction=_direction;
}


void FillCommand::begin(){
	DEBUG_PRINT("Begin Fill");
	done = false;
	timer.reset();
	fillIndex = (direction == Direction::FORWARD ?  0 : strip.length-1);
}


void FillCommand::update(){
	uint16_t numToFill = min(timer.elapsedTime()/rate,strip.length); //How many need to be filled
	int16_t stopPoint = (direction == Direction::FORWARD ? numToFill : strip.length-numToFill-1); 
	int16_t index = fillIndex;
	while(index != stopPoint){
		strip.leds[index] = fillColor;
		if(direction == Direction::FORWARD){
			index++;
		}else{
			index--;
		}
	}
	done = (numToFill == strip.length);
	#ifdef DEBUG
	if(done){
		DEBUG_PRINT("Fill Done");
	}
	#endif
}

