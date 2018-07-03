
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


FillCommand fillInRed = FillCommand(ledsA, NUM_LEDS, CRGB::Red, RATE, FillCommand::Direction::FORWARD);
FillCommand fillInBlue = FillCommand(ledsA, NUM_LEDS, CRGB::Blue, RATE, FillCommand::Direction::FORWARD);
FillCommand fillInGreen = FillCommand(ledsA, NUM_LEDS, CRGB::Green, RATE, FillCommand::Direction::FORWARD);
FillCommand fillOutBlack = FillCommand(ledsA, NUM_LEDS, CRGB::Black, RATE, FillCommand::Direction::REVERSE);

FadeCommand fadeInRed = FadeCommand(ledsB, NUM_LEDS, CRGB::Red, FADE_DURATION, FadeCommand::Direction::IN);
FadeCommand fadeOutRed = FadeCommand(ledsB, NUM_LEDS, CRGB::Red, FADE_DURATION, FadeCommand::Direction::OUT);
FadeCommand fadeInBlue = FadeCommand(ledsB, NUM_LEDS, CRGB::Blue, FADE_DURATION, FadeCommand::Direction::IN);
FadeCommand fadeOutBlue = FadeCommand(ledsB, NUM_LEDS, CRGB::Blue, FADE_DURATION, FadeCommand::Direction::OUT);
FadeCommand fadeInGreen = FadeCommand(ledsB, NUM_LEDS, CRGB::Green, FADE_DURATION, FadeCommand::Direction::IN);
FadeCommand fadeOutGreen = FadeCommand(ledsB, NUM_LEDS, CRGB::Green, FADE_DURATION, FadeCommand::Direction::OUT);

DelayCommand fillDelay = DelayCommand(500);
DelayCommand fadeDelay = DelayCommand(500);
Command* fillSeqCmds[12] = {&fillInRed,&fillDelay,&fillOutBlack,&fillDelay,&fillInBlue,&fillDelay,&fillOutBlack,&fillDelay,&fillInGreen,&fillDelay,&fillOutBlack,&fillDelay};
CommandSequence fillSeq = CommandSequence(fillSeqCmds,12);
Command* fadeSeqCmds[12] = {&fadeInRed,&fadeDelay,&fadeOutRed,&fadeDelay,&fadeInBlue,&fadeDelay,&fadeOutBlue,&fadeDelay,&fadeInGreen,&fadeDelay,&fadeOutGreen,&fadeDelay};
CommandSequence fadeSeq = CommandSequence(fadeSeqCmds,12);

Command* parallelCmds[2] = {&fillSeq,&fadeSeq};
ParallelCommand mainCmd = ParallelCommand(parallelCmds,2);

LoopCommand loopCmd = LoopCommand(LoopCommand::INFINITE,&mainCmd);
bool done;


void setup() {

  #ifdef DEBUG
    Serial.begin(19200);
    DEBUG_PRINT("Welcome to the Simple Animation Demo!");
  #endif

    delay(1000);
    done = false;
    FastLED.addLeds<NEOPIXEL, LED_PIN_A>(ledsA, NUM_LEDS);
    FastLED.addLeds<NEOPIXEL, LED_PIN_B>(ledsB, NUM_LEDS);

    loopCmd.begin();
}

void loop() {
  if(!loopCmd.isDone()){
    loopCmd.update();
    FastLED.show(); 
  }
  delay(LOOP_DELAY);
}
