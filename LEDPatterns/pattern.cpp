#include "pattern.h"

Pattern::Pattern() {}

Pattern::Pattern(CRGB *a, int s, int del, uint8_t sat, uint8_t bright)
{
  arr = a;
  size = s;
  saturation = sat;
  brightness = bright;
  delay = del;
}

void Pattern::setCHSV(int pos, uint8_t hue, uint8_t bright)
{
  if (pos < size)
  {
    arr[pos] = CHSV(hue, saturation, bright);
  }
}

int Pattern::getDelay()
{
  return delay;
}

void move() {}

void show()
{
  FastLED.show();
}

void trigger() {}

void Pattern::clear()
{
  FastLED.clear();
}