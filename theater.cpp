#include "theater.h"

Theater::Theater(
    CRGB *ledArray,
    int numLeds,
    int delay,
    uint8_t hue,
    uint8_t saturation,
    uint8_t brightness)
    : Pattern(ledArray, numLeds, delay, saturation, brightness)
{
    hue = hue;
    offset = 0;
}

void Theater::setHue(uint8_t h)
{
    hue = h;
}

void Theater::show()
{
    for (int i = 0; i < size; i++)
    {
        if ((i + offset) % 2 == 0)
        {
            setCHSV(i, hue + i, brightness);
        }
        else
        {
            setCHSV(i, hue, 0);
        }
    }
    hue++;
}

void Theater::move()
{
    if (offset == 0)
    {
        offset = 1;
    }
    else
    {
        offset = 0;
    }
}

void Theater::trigger()
{
    hue += 100;
}
