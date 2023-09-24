#pragma once

#define NUM_LEDS 100

#include <memory>
#include <FastLED.h>
#include <SimpleCLI.h>

#include "components/Animation.hpp"

namespace Program {

// bool isRunning = true;
extern Animation* anim;
extern CRGB leds[NUM_LEDS];

extern CRGB color;


// </namespace Program>
}