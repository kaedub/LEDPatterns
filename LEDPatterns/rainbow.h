#ifndef RAINBOW_H
#define RAINBOW_H
#include "pattern.h"

class Rainbow : public Pattern
{
private:
    uint8_t hue;
    uint8_t hueModifier;
    uint8_t glitterOn;

public:
    Rainbow(CRGB *ledArray, int numLeds, int delay, uint8_t hue, uint8_t sat, uint8_t bright);
    void setHueModifier(uint8_t h);
    void show(void);
    void move(void);
    void trigger(void);
};

#endif