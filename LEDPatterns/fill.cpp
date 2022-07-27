#include <math.h>
#include "fill.h"

Fill::Fill(
    CRGB *ledArray,
    int numLeds,
    int delay,
    uint8_t saturation,
    uint8_t brightness,
    uint8_t hueMod = 1)
    : Pattern(ledArray, numLeds, delay, saturation, brightness)
{
    hue = 0;
    hueModifier = 35;
    fillSize = size;
    steps = 0;
    direction = 1;
    fillCount = ceil(size / fillSize);
}

void Fill::setFillSize(int s)
{
    fillSize = s;
    fillCount = ceil(size / fillSize);
}

void Fill::setHue(uint8_t h)
{
    hue = h;
}

void Fill::setHueModifier(uint8_t h)
{
    hueModifier = h;
}

void Fill::move()
{
    if (steps >= fillSize - 1)
    {
        hue += hueModifier;
        direction = -direction;
        steps = 0;
    }
    else
    {
        steps++;
    }
}

void Fill::show()
{
    int pos;
    int limit;
    switch (direction)
    {
    case -1:
        pos = fillSize - 1;
        limit = fillSize - steps - 1;
        break;
    case 1:
        pos = 0;
        limit = steps;
        break;
    }
    for (int count = 0; count < fillCount; count++)
    {
        int start = pos + (count * fillSize);
        int end = limit + (count * fillSize);
        bool fillPending = true;
        while (fillPending)
        {

            if (direction > 0)
            {
                fillPending = !(start >= end);
            }
            else
            {
                fillPending = !(start <= end);
            }
            setCHSV(start, hue, brightness);

            start += direction;
        }
    }
}

void Fill::trigger()
{
    this->clear();
    steps = 0;
}
