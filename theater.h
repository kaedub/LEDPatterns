#pragma once
#include "pattern.h"

class Theater : public Pattern
{
private:
    uint8_t offset;
    uint8_t hue;
    void setHue(uint8_t h);

public:
    Theater(CRGB *ledArray, int numLeds, int delay, uint8_t hue, uint8_t sat, uint8_t bright);
    void show(void);
    void move(void);
    void trigger(void);
};
