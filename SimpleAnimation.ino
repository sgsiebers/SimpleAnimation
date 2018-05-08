
#include "FastLED.h"
#include "SimpleAnimation.h"

#define LED_PIN_A 4
#define LED_PIN_B 5

#define NUM_LEDS 50
#define RATE 10
#define FADE_DURATION 500
#define LOOP_DELAY 1

CRGB ledsA[NUM_LEDS];
CRGB ledsB[NUM_LEDS];

LedStrip stripA = {ledsA, NUM_LEDS};
LedStrip stripB = {ledsB, NUM_LEDS};

FillCommand fillInRed = FillCommand();
FillCommand fillInBlue = FillCommand();
FillCommand fillInGreen = FillCommand();

FillCommand fillOutBlack = FillCommand();
FadeCommand fadeInRed = FadeCommand();
FadeCommand fadeOutRed = FadeCommand();
FadeCommand fadeInBlue = FadeCommand();
FadeCommand fadeOutBlue = FadeCommand();
FadeCommand fadeInGreen = FadeCommand();
FadeCommand fadeOutGreen = FadeCommand();

DelayCommand delayCmd = DelayCommand();
CommandSequence<12> fillSeq = CommandSequence<12>();
CommandSequence<9> fadeSeq = CommandSequence<9>();
ParallelCommand<2> mainCmd = ParallelCommand<2>();

LoopCommand loopCmd = LoopCommand();
bool done;


void setup() {

  #ifdef DEBUG
    Serial.begin(19200);
    DEBUG_PRINT("Hello World!");
  #endif

    
    delay(1000);
    done = false;
    FastLED.addLeds<NEOPIXEL, LED_PIN_A>(stripA.leds, NUM_LEDS);
    FastLED.addLeds<NEOPIXEL, LED_PIN_B>(stripB.leds, NUM_LEDS);

    delayCmd.init(500);
    
    fillInRed.init(stripA, CRGB::Red, RATE, FillCommand::Direction::FORWARD);
    fillInBlue.init(stripA, CRGB::Blue, RATE, FillCommand::Direction::FORWARD);
    fillInGreen.init(stripA, CRGB::Green, RATE, FillCommand::Direction::FORWARD);
    fillOutBlack.init(stripA, CRGB::Black, RATE, FillCommand::Direction::REVERSE);
    fillSeq.add(&fillInRed).add(&delayCmd).add(&fillOutBlack).add(&delayCmd).add(&fillInBlue).add(&delayCmd).add(&fillOutBlack).add(&delayCmd).add(&fillInGreen).add(&delayCmd).add(&fillOutBlack).add(&delayCmd);
    
    fadeInRed.init(stripB, CRGB::Red, FADE_DURATION, FadeCommand::Direction::IN);
    fadeOutRed.init(stripB, CRGB::Red, FADE_DURATION, FadeCommand::Direction::OUT);
    fadeInBlue.init(stripB, CRGB::Blue, FADE_DURATION, FadeCommand::Direction::IN);
    fadeOutBlue.init(stripB, CRGB::Blue, FADE_DURATION, FadeCommand::Direction::OUT);
    fadeInGreen.init(stripB, CRGB::Green, FADE_DURATION, FadeCommand::Direction::IN);
    fadeOutGreen.init(stripB, CRGB::Green, FADE_DURATION, FadeCommand::Direction::OUT);
    fadeSeq.add(&fadeInRed).add(&fadeOutRed).add(&delayCmd).add(&fadeInBlue).add(&fadeOutBlue).add(&delayCmd).add(&fadeInGreen).add(&fadeOutGreen).add(&delayCmd);

    mainCmd.add(&fillSeq).add(&fadeSeq);    
    loopCmd.init(LoopCommand::INFINITE,&mainCmd);
    loopCmd.begin();
}

void loop() {
  if(!loopCmd.isDone()){
    loopCmd.update();
    FastLED.show(); 
  }
  delay(LOOP_DELAY);
}
