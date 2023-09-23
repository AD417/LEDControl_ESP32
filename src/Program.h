#define NUM_LEDS 100

#include <memory>
#include <FastLED.h>

#include "components/Animation.hpp"

namespace Program {

bool isRunning = true;
Animation* anim;
CRGB leds[NUM_LEDS];

CRGB color = CRGB::White;




// </namespace Program>
}