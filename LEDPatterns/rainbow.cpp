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
    glitterOn = true;
    hueModifier = 1;
}

void Rainbow::setHueModifier(uint8_t h)
{
    hueModifier = h;
}

void Rainbow::show()
{
    for (int i = 0; i < size; i++)
    {
        setCHSV(i, hue + i, brightness);
        if (glitterOn)
        {
            int chanceOfGlitter = 30;
            if (random8(100) < chanceOfGlitter)
            {
                setCHSV(i, hue + 100, brightness);
            }
        }
    }
    Pattern::show();
}

void Rainbow::move()
{
    hue += hueModifier;
}

void Rainbow::trigger()
{
    // hue += 100;
}
