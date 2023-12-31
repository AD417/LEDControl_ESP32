#pragma once

#include <string.h>
#include <FastLED.h>


class Animation
{
public:
    Animation();
    Animation(CRGB color);
    Animation(CRGB::HTMLColorCode color);

    double frame();
    int frameDiscrete();
    virtual void updateColorTo(CRGB newColor);
    virtual bool isComplete();
    virtual Animation *nextAnimation();
    virtual void applyTo(CRGB strip[], int len) = 0;
    virtual String toString();

protected:
    CRGB color;
    unsigned long frameInterval = 0;

    bool interrupt = false;
    CRGB darkColor = CRGB::Black;
    unsigned long startTime = millis();
};