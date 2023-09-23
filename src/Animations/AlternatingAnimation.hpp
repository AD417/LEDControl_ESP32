#include "components/Animation.hpp"

class AlternatingAnimation : public Animation
{
public:
    AlternatingAnimation(CRGB color);
    AlternatingAnimation(CRGB color, unsigned long frameInterval);
    AlternatingAnimation(CRGB color, unsigned long frameInterval, int width);
    void applyTo(CRGB strip[], int len) override;
private:
    int width = 2;
};