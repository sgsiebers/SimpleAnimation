# SimpleAnimation
Arduino library for animating basic sequences of timed commands. See my [Contribution Guidelines](CONTRIBUTING.md) for an explanation of where this came from and how it's maintained.

## Command Descriptions 

#### Basics
+ **Timer**: A basic timer to measure elapsed time. 
+ **DelayCommand**: Waits a specified period of time.
+ **CommandSequence**: Executes a sequence of commands in order, one after another.
+ **ParallelCommand**: Executes multiple commands at the same time.
+ **LoopCommand**: Repetitively loops a command a fixed number of times (or infinitely). Useful when combined with sequences.

#### LED Control
For use with NeoPixel and other programmable LED strips.  Based on the excellent [FastLED](https://github.com/FastLED/FastLED) library.

+ **FadeCommand**: Fade a strip of LED's in or out with a specific color over a period of time.
+ **FillCommand**: Fill a strip of LED's in or out with a specific color over a period of time.
+ **FlashCommand**: Flash a strip of LED's a specific color a specified number of times over a period of time. 

#### Misc. 
+ **SoundCommand**: Triggers a sound pin on an [Adafruit Mini Sound Board](https://www.adafruit.com/product/2342)
+ **PinCommand**: Time controlled toggling of digital IO pins.  Useful for controlling timing of relays.


See [SimpleAnimation.ino](SimpleAnimation.ino) for more detailed examples of how to use each Command.
