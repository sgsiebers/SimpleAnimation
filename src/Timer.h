#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>


class Timer{

  public:
    Timer();
    Timer(uint16_t _duration);
        
    void reset();
    uint32_t elapsedTime();
    bool expired();

  private:
    uint16_t duration;
    uint32_t startTime;

};
#endif

