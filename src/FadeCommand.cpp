#include "FadeCommand.h"




FadeCommand::FadeCommand() : timer(Timer()){}


void FadeCommand::init(LedStrip & _strip, CRGB _color, uint32_t _duration, Direction _direction){
    strip = _strip;
    color = _color;
    duration = _duration;
    direction = _direction;   
}



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
    for(uint16_t i=0; i<strip.length;i++){
        strip.leds[i]= scaledColor;
    }
}
