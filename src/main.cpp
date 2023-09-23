#include <Arduino.h>
#include <FastLED.h>

#include "Animations/AlternatingAnimation.hpp"
#include "Animations/FillAnimation.hpp"
#include "Animations/PulseAnimation.hpp"
#include "Animations/WaveAnimation.hpp"
#include "components/Animation.hpp"

#define NUM_LEDS 100
CRGB leds[NUM_LEDS];
Animation *anim = new WaveAnimation(CRGB::Red);

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, 12, BRG>(leds, NUM_LEDS);
  Serial.begin(9600);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  anim->applyTo(leds, NUM_LEDS);
  FastLED.show();
  delay(10);
}