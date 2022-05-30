#pragma once
#include "pattern.h"

class Comet : public Pattern
{
private:
    static const int maxComets = 30;
    // This is an array of the positions of each comet. One for each comet moving through the strip.
    // The positions are incremented to move the position of each comet. A value of -1 means do not show.
    int cometPositions[maxComets];
    // This a parallel array to comet_positions and holds the hue for each comet moving through the strip.
    int cometHues[maxComets];
    int tailLength;
    // bool sparkleTail;
    void fade();

public:
    Comet(CRGB *ledArray, int numLeds, int delay, int tail, uint8_t sat, uint8_t bright);
    void show(void);
    void move(void);
    void trigger(void);
    void clear(void);
};
