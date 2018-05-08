#include "Timer.h"

#include <Arduino.h>


Timer::Timer(): duration(0),startTime(0) {}


void Timer::setDuration(uint32_t _duration){
	duration=_duration;
}

void Timer::reset(){
  startTime = millis();
}

uint32_t Timer::elapsedTime(){
  if(startTime > 0){
    return millis()-startTime;
  }
  return -1;
}


bool Timer::expired(){
  if(duration == 0 || startTime == 0){
    return true;
  }
  return elapsedTime() > duration;
}

