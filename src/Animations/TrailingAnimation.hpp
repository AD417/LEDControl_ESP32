#include "components/Animation.hpp"
#include "Program.h"

class TrailingAnimation : public Animation
{
public:
    TrailingAnimation(CRGB color);
    TrailingAnimation(CRGB color, unsigned long frameInterval);
    TrailingAnimation(CRGB color, unsigned long frameInterval, int width);
    void applyTo(CRGB strip[], int len) override;
private:
    int width = 20;
    int trails[];
};