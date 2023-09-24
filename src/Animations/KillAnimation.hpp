#include "components/Animation.hpp"

class KillAnimation : public Animation
{
public:
    KillAnimation();
    void applyTo(CRGB strip[], int len) override;
};