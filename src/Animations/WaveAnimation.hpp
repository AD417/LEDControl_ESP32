#include "components/Animation.hpp"

class WaveAnimation : public Animation
{
public:
    WaveAnimation(CRGB color);
    WaveAnimation(CRGB color, unsigned long frameInterval);
    WaveAnimation(CRGB color, unsigned long frameInterval, double wavelength);
    void applyTo(CRGB strip[], int len) override;

private:
    double wavelength = 5.0;

    double percentage(double offset);
};