#include "FadeCommand.h"




FadeCommand::FadeCommand(CRGB* _leds, uint16_t _length, CRGB _color, uint16_t _duration, Direction _direction) :
	LedCommand(_leds,_length),
	color(_color),
	duration(_duration),
	direction(_direction),
	timer(Timer()) {}



void FadeCommand::begin(){
    DEBUG_PRINT("Begin Fade");
    done = false;
    timer.reset();
}


void FadeCommand::update(){
    uint32_t et = min(timer.elapsedTime(),duration);
    CRGB scaledColor = color;
    if(et<duration){
        uint8_t scale = 255*et/duration;
        if(direction==Direction::OUT){
            scale = 255-scale;
        }
        scaledColor.nscale8_video(scale);
    }else{
        if(direction == Direction::OUT){
            scaledColor = CRGB::Black;
        }
        DEBUG_PRINT("Fade Done!");
        done = true;
    }
    for(uint16_t i=0; i<length;i++){
        leds[i]= scaledColor;
    }
}
