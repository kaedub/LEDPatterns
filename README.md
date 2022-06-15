## LED Pattern Library

Contains an variety of pattern classes for that use FastLED.

## Installation

Install the FastLED library for Arduino.

Clone the repo then copy the LEDPatterns folder into Arduino libraries folder.

## Example

```C++
#include "comet.h"
#include "theater.h"

#define DATA_PIN 2
#define NUM_LEDS 100

CRGB leds[NUM_LEDS];

const int maxSaturation = 175;
const int maxBrightness = 200;

// Create a Comet pattern object.
const int tailLength = 10;
int cometDelay = 75;
const int cometPeriod = cometDelay * (tailLength * 2);
Comet comet = Comet(leds, NUM_LEDS, cometDelay, tailLength, maxSaturation, maxBrightness);

// Create a Theater pattern object.
int theaterDelay = 250;
int theaterHueMod = 5;
Theater theater = Theater(leds, NUM_LEDS, theaterDelay, maxSaturation, maxBrightness, theaterHueMod);

int patternIndex = 0;
const int patternCount = 2;
Pattern *patterns[patternCount] = {&theater, &comet};

int changePatternPeriod = 5000;
int ledStartMillis;
int triggerStartMillis;
int changeStartMillis;

void setup()
{
    FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);

    ledStartMillis = millis();
    triggerStartMillis = ledStartMillis;
    changeStartMillis = ledStartMillis;
}

void loop()
{
    int currentMillis = millis();
    Pattern *currentPattern = patterns[patternIndex];
    // Move pattern
    if (currentMillis - ledStartMillis >= currentPattern->getDelay())
    {
        currentPattern->move();
        currentPattern->show();
        ledStartMillis = currentMillis;
    }
    // Trigger pattern changes
    if (patternIndex == 0 && currentMillis - triggerStartMillis >= cometPeriod)
    {
        currentPattern->trigger();
        triggerStartMillis = currentMillis;
    }
    // Change pattern
    if (currentMillis - changeStartMillis >= changePatternPeriod)
    {
        patternIndex = (patternIndex + 1) % patternCount;
        changeStartMillis = currentMillis;
    }
}
```
