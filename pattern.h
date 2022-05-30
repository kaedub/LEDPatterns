#pragma once
#include <FastLED.h>

class Pattern
{
protected:
    // LED array and size of strip.
    CRGB *arr;
    int size;
    // Delay time in milliseconds.
    int delay;
    // The max color saturation value. Colors will appear more white with lower values. (0-255)
    uint8_t saturation;
    // The max brightness value. (0-255)
    uint8_t brightness;

public:
    Pattern();
    Pattern(CRGB *arr, int size, int delay, uint8_t sat, uint8_t bright);
    void setCHSV(int pos, uint8_t hue, uint8_t brightness);
    int getDelay();
    virtual void move(void);
    virtual void show(void);
    virtual void trigger(void);
};