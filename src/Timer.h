#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>


class Timer{

  public:
    Timer();
        
    void reset();
    void setDuration(uint32_t _duration);
    uint32_t elapsedTime();
    bool expired();

  private:
    uint32_t duration;
    uint32_t startTime;

};
#endif

