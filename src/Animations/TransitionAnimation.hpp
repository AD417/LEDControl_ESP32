#include <FastLED.h>

#include "components/DeltaAnimation.hpp"
#include "components/Animation.hpp"

class TransitionAnimation : public DeltaAnimation 
{
public:
    TransitionAnimation(
        Animation * currentAnimation, 
        Animation * nextAnimation, 
        unsigned long transitionInterval
    );
private:
    void blend(CRGB mainStrip[], CRGB otherStrip[], int len) override;
};