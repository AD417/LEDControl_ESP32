#include "FlashAnimation.hpp"

#include <FastLED.h>

#include "FillAnimation.hpp"

// Thanks, I hate it.
FlashAnimation::FlashAnimation(unsigned long interval, CRGB color, Animation * currentAnimation)
        : DeltaAnimation(new FillAnimation(color), currentAnimation, interval) {}

void FlashAnimation::blend(CRGB mainStrip[], CRGB otherStrip[], int len) {
    // No further action necessary. 
    // mainStrip is the FillAnimation we are interrupting using. We don't edit it.
}