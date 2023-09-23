

#include "components/Animation.hpp"
#include "AlternatingAnimation.hpp"

AlternatingAnimation::AlternatingAnimation(
    CRGB color, 
    unsigned long frameInterval,
    int width
) : AlternatingAnimation(color, frameInterval) {
    this->width = width;
}

AlternatingAnimation::AlternatingAnimation(
    CRGB color, 
    unsigned long frameInterval
) : Animation(color) {
    this->frameInterval = frameInterval;
} 

AlternatingAnimation::AlternatingAnimation(CRGB color) : Animation(color) {
    this->frameInterval = 500;
}

void AlternatingAnimation::applyTo(CRGB strip[], int len) {
    int frame = this->frameDiscrete();
    for (int i = 0; i < len; i++) {
        if ((i + frame) % width == 0) {
            strip[i] = this->color;
        } else {
            strip[i] = this->darkColor;
        }
    }
}