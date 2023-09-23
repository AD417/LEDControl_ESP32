#include "math.h"

#include "components/Animation.hpp"
#include "PulseAnimation.hpp"

PulseAnimation::PulseAnimation(
    CRGB color, 
    unsigned long frameInterval
) : Animation(color) {
    this->frameInterval = frameInterval;
} 

PulseAnimation::PulseAnimation(CRGB color) : Animation(color) {
    this->frameInterval = 3000;
}

void PulseAnimation::applyTo(CRGB strip[], int len) {
    double percentage = this->percentage();
    // XXX: Multiplication of CRGB and double does not do what you expect!!!
    CRGB currentColor = CRGB(
        (int) (this->color.r * percentage),
        (int) (this->color.g * percentage),
        (int) (this->color.b * percentage)
    );
    for (int i = 0; i < len; i++) {
        strip[i] = currentColor;
    }
}

double PulseAnimation::percentage() {
    return 0.5 * (1.0 - std::cos(2 * PI * this->frame()));
}