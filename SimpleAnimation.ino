
#include "FastLED.h"
#include "SimpleAnimation.h"

#define LED_PIN_A 5
#define LED_PIN_B 6
#define LED_PIN_C 7
#define PINCOMMAND_PIN 53

#define NUM_LEDS 50
#define RATE 10
#define FADE_DURATION 500
#define LOOP_DELAY 1

CRGB ledsA[NUM_LEDS];
CRGB ledsB[NUM_LEDS];
CRGB ledsC[NUM_LEDS];

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

PinCommand setToLow = PinCommand(PINCOMMAND_PIN, LOW, 1000);
PinCommand setToHigh = PinCommand(PINCOMMAND_PIN, HIGH, 1000);








DelayCommand fillDelay = DelayCommand(500);
DelayCommand fadeDelay = DelayCommand(500);
Command* fillSeqCmds[12] = {&fillInRed,&fillDelay,&fillOutBlack,&fillDelay,&fillInBlue,&fillDelay,&fillOutBlack,&fillDelay,&fillInGreen,&fillDelay,&fillOutBlack,&fillDelay};
CommandSequence fillSeq = CommandSequence(fillSeqCmds,12);
Command* fadeSeqCmds[12] = {&fadeInRed,&fadeDelay,&fadeOutRed,&fadeDelay,&fadeInBlue,&fadeDelay,&fadeOutBlue,&fadeDelay,&fadeInGreen,&fadeDelay,&fadeOutGreen,&fadeDelay};
CommandSequence fadeSeq = CommandSequence(fadeSeqCmds,12);
Command* pinCmds [2] = {&setToHigh, &setToLow};
CommandSequence pinSeq = CommandSequence(pinCmds, 2);
LoopCommand pinLoop = LoopCommand(3,&pinSeq);

FlashCommand flashCmd = FlashCommand(ledsC, NUM_LEDS, CRGB::MidnightBlue, 5000, 10);

Command* parallelCmds[4] = {&fillSeq,&fadeSeq, &flashCmd, &pinLoop};
ParallelCommand mainCmd = ParallelCommand(parallelCmds,4);

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
    FastLED.addLeds<NEOPIXEL, LED_PIN_C>(ledsC, NUM_LEDS);

    pinMode(PINCOMMAND_PIN,OUTPUT);
    digitalWrite(PINCOMMAND_PIN,LOW);


    loopCmd.begin();
}

void loop() {
  if(!loopCmd.isDone()){
    loopCmd.update();
    FastLED.show(); 
  }
  delay(LOOP_DELAY);
}
