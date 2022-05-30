#include "rainbow.h"

Rainbow::Rainbow(
    CRGB *ledArray,
    int numLeds,
    int delay,
    uint8_t hue,
    uint8_t saturation,
    uint8_t brightness)
    : Pattern(ledArray, numLeds, delay, saturation, brightness)
{
    hue = hue;
}

void Rainbow::show()
{
    for (int i = 0; i < size; i++)
    {
        setCHSV(i, hue + i, brightness);
    }
}

void Rainbow::move()
{
    hue++;
}

void Rainbow::trigger()
{
    hue += 100;
}
