#include "comet.h"

Comet::Comet(
    CRGB *ledArray,
    int numLeds,
    int delay,
    int tail,
    uint8_t saturation,
    uint8_t brightness)
    : Pattern(ledArray, numLeds, delay, saturation, brightness)
{
    tailLength = tail;
    sparkleTail = true;
    for (int i = 0; i < maxComets; i++)
    {
        cometPositions[i] = -1;
    }
}

void Comet::show()
{
    for (int i = 0; i < maxComets; i++)
    {
        if (cometPositions[i] >= 0 && cometPositions[i] <= size + tailLength)
        {
            setCHSV(cometPositions[i], cometHues[i], brightness);
        }
    }
    fade();
    Pattern::show();
}

void Comet::move()
{
    for (int i = 0; i < maxComets; i++)
    {
        if (cometPositions[i] >= 0)
        {
            if (cometPositions[i] >= size + tailLength)
            {
                cometPositions[i] = -1;
            }
            else
            {
                cometPositions[i]++;
            }
        }
    }
}

void Comet::trigger()
{
    int i = 0;
    while (i >= 0 && i < maxComets)
    {
        if (cometPositions[i] < 0)
        {
            cometPositions[i] = 0;
            cometHues[i] = random8();
            i = -1;
        }
        else
        {
            i++;
        }
    }
}

void Comet::clear()
{
    for (int i = 0; i < maxComets; i++)
    {
        cometPositions[i] = -1;
    }
    Pattern::clear();
}

void Comet::fade()
{
    for (int i = 0; i < maxComets; i++)
    {
        for (int tailSegment = 0; tailSegment < tailLength; tailSegment++)
        {
            int segmentPos = cometPositions[i] - (tailSegment + 1);
            int segmentBrightness = brightness - (brightness / tailLength) * (tailSegment + 1);
            if (segmentPos >= 0 && segmentPos < size)
            {
                int h = cometHues[i];
                if (sparkleTail && tailSegment > 1 && tailSegment != tailLength - 1)
                {
                    int chanceOfSparkle = 50;
                    if (random8(100) < chanceOfSparkle)
                    {
                        h += random8(25);
                        segmentBrightness += random8(brightness / 2);
                    }
                }
                setCHSV(segmentPos, h, segmentBrightness);
            }
        }
    }
}
