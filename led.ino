#include "comet.h"
#include "theater.h"

#define NUM_LEDS 300

#define DATA_PIN 9

CRGB leds[NUM_LEDS];

// The max color saturation value. Colors will appear more white with lower values. (0-255)
const int maxSaturation = 175;
// The max brightness value. (0-255)
const int maxBrightness = 130;

// Comet pattern object.
const int tailLength = 25;
int cometDelay = 10;
Comet comet(leds, NUM_LEDS, cometDelay, tailLength, maxSaturation, maxBrightness);

// Theater pattern object.
uint8_t initHue = 15;
int theaterDelay = 100;
Theater theater(leds, NUM_LEDS, theaterDelay, initHue, maxSaturation, maxBrightness);

Pattern *currentPattern = &comet;

void nextPattern()
{
  FastLED.clear();
}

int startMillis;
void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
  }
  delay(1000);

  FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
  // initializePatterns();
  startMillis = millis();
}

void loop()
{
  currentPattern->move();
  currentPattern->show();
  FastLED.show();
  delay(currentPattern->getDelay());
}

void serialEvent()
{
  while (Serial.available())
  {
    // get the new byte:
    char inChar = (char)Serial.read();

    Serial.println(inChar);
    if (inChar == 'p')
    {
      nextPattern();
    }
    else if (inChar == 'c')
    {
      currentPattern->trigger();
    }
  }
}