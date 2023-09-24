#include "Program.h"

namespace Program {

Animation * anim;
CRGB leds[NUM_LEDS];

CRGB color = CRGB::White;
CRGB flashColor = CRGB::Red;

bool isInterrupted = false;

}