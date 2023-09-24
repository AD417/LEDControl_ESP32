#include <FastLED.h>

#include "components/DeltaAnimation.hpp"

class FlashAnimation : public DeltaAnimation 
{
public:
    FlashAnimation(unsigned long interval, CRGB color, Animation * currentAnimation);
private:
    void blend(CRGB mainStrip[], CRGB otherStrip[], int len) override;
};