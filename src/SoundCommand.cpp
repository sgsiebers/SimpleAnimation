#include "SoundCommand.h"



SoundCommand::SoundCommand(const uint8_t _pin, const uint16_t _duration) : pin(_pin), pinActive(false), playTimer(Timer(_duration+SOUND_PIN_HOLD_TIME))  {}


void SoundCommand::begin(){
  DEBUG_PRINT("Begin sound");
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
  playTimer.reset();
  pinActive = true;
  done = false;
}


void SoundCommand::update(){
  if(pinActive && playTimer.elapsedTime() > SOUND_PIN_HOLD_TIME){
    DEBUG_PRINT("Sound trigger done");
    digitalWrite(pin, HIGH);    
    pinActive = false;
  }
  done = playTimer.expired();
  if(done){
        DEBUG_PRINT("Sound Done");
  }
}



