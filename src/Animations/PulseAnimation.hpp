#include "components/Animation.hpp"

class PulseAnimation : public Animation
{
public:
    PulseAnimation(CRGB color);
    PulseAnimation(CRGB color, unsigned long frameInterval);
    void applyTo(CRGB strip[], int len) override;

private:
    double percentage();
};