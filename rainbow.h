#pragma once
#include "pattern.h"

class Rainbow : public Pattern
{
private:
    uint8_t hue;

public:
    Rainbow(CRGB *ledArray, int numLeds, int delay, uint8_t hue, uint8_t sat, uint8_t bright);
    void show(void);
    void move(void);
    void trigger(void);
};
