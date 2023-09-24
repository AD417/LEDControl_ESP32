#include "TransitionAnimation.hpp"

#include <FastLED.h>

#include "components/Animation.hpp"

// Thanks, I hate it.
TransitionAnimation::TransitionAnimation(
        Animation * currentAnimation, 
        Animation * nextAnimation, 
        unsigned long transitionInterval
) : DeltaAnimation(currentAnimation, nextAnimation, transitionInterval) {}


void TransitionAnimation::blend(CRGB mainStrip[], CRGB otherStrip[], int len) {
    for (int i = 0; i < len; i++) {
        CRGB newColor = CRGB(
            (int) (otherStrip[i].r * transitionPercent() + mainStrip[i].r * (1 - transitionPercent())),
            (int) (otherStrip[i].g * transitionPercent() + mainStrip[i].g * (1 - transitionPercent())),
            (int) (otherStrip[i].b * transitionPercent() + mainStrip[i].b * (1 - transitionPercent()))
        );
        mainStrip[i] = newColor;
    }
}