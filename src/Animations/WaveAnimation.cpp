#include "cmath"

#include "components/Animation.hpp"
#include "WaveAnimation.hpp"

WaveAnimation::WaveAnimation(
    CRGB color, 
    unsigned long frameInterval,
    double wavelength
) : WaveAnimation(color, frameInterval) {
    this->wavelength = wavelength;
} 

WaveAnimation::WaveAnimation(
    CRGB color, 
    unsigned long frameInterval
) : Animation(color) {
    this->frameInterval = frameInterval;
} 

WaveAnimation::WaveAnimation(CRGB color) : Animation(color) {
    this->frameInterval = 300;
}

void WaveAnimation::applyTo(CRGB strip[], int len) {

    double frame = this->frame();
    CRGB pixelColor;
    for (int i = 0; i < len; i++) {
        // Bruh, no double % double?
        double offset = std::fmod(i + frame, this->wavelength);
        double percent = percentage(offset);
        // XXX: Multiplication of CRGB and double does not do what you expect!!!
        CRGB currentColor = CRGB(
            (int) (this->color.r * percent),
            (int) (this->color.g * percent),
            (int) (this->color.b * percent)
        );
        strip[i] = currentColor;
    }
}

double WaveAnimation::percentage(double offset) {
    return 0.5 * (1.0 - std::cos(2 * PI * offset / this->wavelength));
}