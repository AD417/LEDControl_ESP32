#include "components/Animation.hpp"
#include "TrailingAnimation.hpp"

TrailingAnimation::TrailingAnimation(
    CRGB color, 
    unsigned long frameInterval,
    int width
) : TrailingAnimation(color, frameInterval) {
    this->width = width;
}

TrailingAnimation::TrailingAnimation(
    CRGB color, 
    unsigned long frameInterval
) : Animation(color) {
    this->frameInterval = frameInterval;
} 

TrailingAnimation::TrailingAnimation(CRGB color) : Animation(color) {
    this->frameInterval = 500;
}

void TrailingAnimation::applyTo(CRGB strip[], int len) {
    int frame = this->frameDiscrete();
    for (int i = 0; i < len; i++) {
        if ((i + frame) % width == 0) {
            strip[i] = this->color;
        } else {
            strip[i] = this->darkColor;
        }
    }
}