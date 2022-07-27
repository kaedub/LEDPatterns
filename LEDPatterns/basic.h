#ifndef Basic_H
#define Basic_H
#include "pattern.h"

class Basic : public Pattern
{
private:
    uint8_t hue;
    uint8_t hueModifier;
    void setHue(uint8_t h);

public:
    Basic(CRGB *ledArray, int numLeds, int delay, uint8_t hue, uint8_t sat, uint8_t bright);
    void setHueModifier(uint8_t h);
    void show(void);
    void move(void);
    void trigger(void);
};

#endif