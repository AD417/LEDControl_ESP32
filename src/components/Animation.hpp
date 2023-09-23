#pragma once

#include <string.h>
#include <FastLED.h>


class Animation
{
public:
    Animation(CRGB color);
    Animation(CRGB::HTMLColorCode color);

    double frame();
    int frameDiscrete();
    void updateColorTo(CRGB new_color);
    virtual bool isComplete();
    virtual Animation *nextAnimation();
    virtual void applyTo(CRGB strip[], int len) = 0;
    virtual String toString();

protected:
    CRGB color;
    unsigned long frameInterval = 0;

    bool interrupt = false;
    CRGB dark_color = CRGB::Black;
    unsigned long start_time = millis();
};