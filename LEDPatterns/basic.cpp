#include "basic.h"

Basic::Basic(
    CRGB *ledArray,
    int numLeds,
    int delay,
    uint8_t hue,
    uint8_t saturation,
    uint8_t brightness)
    : Pattern(ledArray, numLeds, delay, saturation, brightness)
{
    hue = hue;
    hueModifier = 0;
}

void Basic::setHue(uint8_t h)
{
    hue = h;
}

void Basic::setHueModifier(uint8_t h)
{
    hueModifier = h;
}

void Basic::show()
{
    for (int i = 0; i < size; i++)
    {
        setCHSV(i, hue, brightness);
    }
}

void Basic::move()
{
    hue++;
}

void Basic::trigger()
{
    // hue += 100;
}
