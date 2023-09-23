

#include "components/Animation.hpp"
#include "FillAnimation.hpp"

FillAnimation::FillAnimation(CRGB color) : Animation::Animation(color) {}

void FillAnimation::applyTo(CRGB strip[], int len) {
    for (int i = 0; i < len; i++) {
        strip[i] = this-> color;
    }
}