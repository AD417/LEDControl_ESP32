#include "components/Animation.hpp"

class FillAnimation : public Animation
{
public:
    FillAnimation(CRGB color);
    void applyTo(CRGB strip[], int len) override;
};