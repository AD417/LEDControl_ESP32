#include "components/Animation.hpp"

class FestiveTwinkleAnimation : public Animation
{
public:
    FestiveTwinkleAnimation(unsigned long frameInterval);
    FestiveTwinkleAnimation(unsigned long frameInterval, double wavelength);
    void applyTo(CRGB strip[], int len) override;

private:
    double wavelength = 2.0;

    double percentage(double offset);
};