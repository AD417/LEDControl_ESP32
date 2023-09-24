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
            (int) (mainStrip[i].r * transitionPercent() + otherStrip[i].r * (1 - transitionPercent())),
            (int) (mainStrip[i].g * transitionPercent() + otherStrip[i].g * (1 - transitionPercent())),
            (int) (mainStrip[i].b * transitionPercent() + otherStrip[i].b * (1 - transitionPercent()))
        );
        mainStrip[i] = newColor;
    }
}