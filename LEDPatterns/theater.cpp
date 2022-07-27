#include "theater.h"

Theater::Theater(
    CRGB *ledArray,
    int numLeds,
    int delay,
    uint8_t saturation,
    uint8_t brightness,
    uint8_t hueMod = 1)
    : Pattern(ledArray, numLeds, delay, saturation, brightness)
{
    hue = 0;
    offset = 0;
    hueModifier = 1;
}

void Theater::setHue(uint8_t h)
{
    hue = h;
}

void Theater::setHueModifier(uint8_t h)
{
    hueModifier = h;
}

void Theater::show()
{
    for (int i = 0; i < size; i++)
    {
        if ((i + offset) % 2 == 0)
        {
            setCHSV(i, hue + 5, brightness);
        }
        else
        {
            setCHSV(i, hue, 0);
        }
    }
    hue += hueModifier;
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
    // hue += 100;
}
