#include <FastLED.h>

#include "components/Animation.hpp"
#include "KillAnimation.hpp"

KillAnimation::KillAnimation() : Animation::Animation(CRGB::Black) {}

void KillAnimation::applyTo(CRGB strip[], int len) {
    for (int i = 0; i < len; i++) {
        strip[i] = CRGB::Black;
    }
}