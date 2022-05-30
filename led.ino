#include "Arduino.h"
#include "comet.h"
#include "theater.h"
#include "rainbow.h"

#define NUM_LEDS 300

#define DATA_PIN 9
#define PATTERN_BUTTON_PIN 7

CRGB leds[NUM_LEDS];

// The max color saturation value. Colors will appear more white with lower values. (0-255)
const int maxSaturation = 175;
// The max brightness value. (0-255)
const int maxBrightness = 130;

// Comet pattern object.
const int tailLength = 25;
int cometDelay = 5;
Comet comet(leds, NUM_LEDS, cometDelay, tailLength, maxSaturation, maxBrightness);

// Theater pattern object.
uint8_t theaterHue = 15;
int theaterDelay = 250;
Theater theater(leds, NUM_LEDS, theaterDelay, theaterHue, maxSaturation, maxBrightness);

// Rainbow pattern object.
uint8_t rainbowHue = 15;
int rainbowDelay = 5;
Rainbow rainbow(leds, NUM_LEDS, rainbowDelay, rainbowHue, maxSaturation, maxBrightness);

Pattern *currentPattern = &comet;

int patternIndex = 0;
void nextPattern()
{
  currentPattern->clear();
  patternIndex = (patternIndex + 1) % 3;
  switch (patternIndex)
  {
  case 0:
    currentPattern = &comet;
    break;
  case 1:
    currentPattern = &theater;
    break;
  case 2:
    currentPattern = &rainbow;
    break;
  }
}

int startMillis;
void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
  }
  delay(1000);

  pinMode(PATTERN_BUTTON_PIN, INPUT);
  FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
  // initializePatterns();
  startMillis = millis();
}

void loop()
{
  int currentMillis = millis();
  checkPatternButton();
  if (currentMillis - startMillis >= currentPattern->getDelay())
  {
    currentPattern->move();
    currentPattern->show();
    FastLED.show();
    startMillis = millis();
  }
  delay(1);
}

int patternButton = LOW;
boolean patternButtonPressed = false;
void checkPatternButton()
{
  patternButton = digitalRead(PATTERN_BUTTON_PIN);
  if (patternButtonPressed == false && patternButton == HIGH)
  {
    patternButtonPressed = true;
    nextPattern();
  }
  else if (patternButton == LOW)
  {
    patternButtonPressed = false;
  }
}

void serialEvent()
{
  while (Serial.available())
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    if (inChar == 'c')
    {
      currentPattern->trigger();
    }
  }
}