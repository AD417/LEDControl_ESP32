#include "cmath"

#include "components/Animation.hpp"
#include "FestiveTwinkleAnimation.h"

FestiveTwinkleAnimation::FestiveTwinkleAnimation(
    unsigned long frameInterval,
    double wavelength
) : FestiveTwinkleAnimation(frameInterval) {
    this->wavelength = wavelength;
} 

FestiveTwinkleAnimation::FestiveTwinkleAnimation(
    unsigned long frameInterval
) : Animation(CRGB::White) {
    this->frameInterval = frameInterval;
}

void FestiveTwinkleAnimation::applyTo(CRGB strip[], int len) {

    double frame = this->frame();
    CRGB baseColor;
    CRGB pixelColor;
    for (int i = 0; i < len; i++) {
        // Serial.println("TESTCAT!");
        switch ((int)((i + frame) / this->wavelength + i) % 3) {    
        case 0: 
            baseColor = CRGB::White;
            break;
        case 1: 
            baseColor = CRGB::Red;
            break;
        case 2: 
            baseColor = CRGB::Green;
            break;
        }
        // Bruh, no double % double?
        double offset = std::fmod(i + frame, this->wavelength);
        double percent = percentage(offset);
        // if (i == 1) Serial.println(percent);
        // XXX: Multiplication of CRGB and double does not do what you expect!!!
        CRGB currentColor = CRGB(
            (int) (baseColor.r * percent),
            (int) (baseColor.g * percent),
            (int) (baseColor.b * percent)
        );
        strip[i] = currentColor;
    }
}

double FestiveTwinkleAnimation::percentage(double offset) {
    static double x;
    x = 0.5 * (1.0 - std::cos(2 * PI * offset / this->wavelength));
    return x; // * x;
}