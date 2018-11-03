#include "FlashCommand.h"



FlashCommand::FlashCommand(CRGB* _leds, uint16_t _length, CRGB _color, uint16_t _duration, uint8_t _numFlashes ):
	LedCommand(_leds,_length),
	color(_color),
	duration(_duration),
	numFlashes(_numFlashes),
	timer(Timer(_duration)) {}



void FlashCommand::begin(){
    DEBUG_PRINT("Begin Flash");
    done = false;
    timer.reset();
    for(uint16_t i=0; i<length;i++){
        leds[i]= CRGB::Black;
    }

}


void FlashCommand::update(){
    uint32_t et = min(timer.elapsedTime(),duration);
    CRGB currentColor = CRGB::Black;
    uint16_t flashInterval = duration/numFlashes;
    if(2*(et % flashInterval) > flashInterval){
    	currentColor = color;
    }
    for(uint16_t i=0; i<length;i++){
        leds[i]= currentColor;
    }
    done = timer.expired();
	#ifdef DEBUG
    	if(done){
    		DEBUG_PRINT("Flash done");
    	}
	#endif
}



