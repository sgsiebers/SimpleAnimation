#ifndef LED_STRIP_H
#define LED_STRIP_H

#include <FastLED.h>

typedef struct LedStrip{
  CRGB* leds;
  uint16_t length;  
} LedStrip;

#endif

