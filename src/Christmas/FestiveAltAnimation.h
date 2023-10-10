#include "components/Animation.hpp"

class FestiveAltAnimation : public Animation
{
public:
    FestiveAltAnimation();
    FestiveAltAnimation(unsigned long frameInterval);
    void applyTo(CRGB strip[], int len) override;
private:
    int width = 3;
};