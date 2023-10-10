

#include "components/Animation.hpp"
#include "FestiveAltAnimation.h"

FestiveAltAnimation::FestiveAltAnimation(
    unsigned long frameInterval
) : Animation(CRGB::White) {
    this->frameInterval = frameInterval;
}

void FestiveAltAnimation::applyTo(CRGB strip[], int len) {
    int frame = this->frameDiscrete();
    for (int i = 0; i < len; i++) {
        switch ((i + frame) % 3) {
        case 0: 
            strip[i] = CRGB::White;
            break;
        case 1: 
            strip[i] = CRGB::Red;
            break;
        case 2: 
            strip[i] = CRGB::Green;
            break;
        }
    }
}