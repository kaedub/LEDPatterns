#include "pattern.h"

Pattern::Pattern() {}

Pattern::Pattern(CRGB *arr, int size, int delay, uint8_t sat, uint8_t bright)
{
  arr = arr;
  size = size;
  saturation = sat;
  brightness = bright;
  delay = delay;
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