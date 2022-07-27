#ifndef Fill_H
#define Fill_H
#include "pattern.h"

class Fill : public Pattern
{
private:
    int fillSize;
    int fillCount;
    int steps;
    int direction;
    uint8_t hue;
    uint8_t hueModifier;
    void setHue(uint8_t h);

public:
    Fill(CRGB *ledArray, int numLeds, int delay, uint8_t hue, uint8_t sat, uint8_t bright);
    void setHueModifier(uint8_t h);
    void setFillSize(int s);
    void show(void);
    void move(void);
    void trigger(void);
};

#endif