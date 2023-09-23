#include <Arduino.h>
#include <FastLED.h>

#include "Animations/FillAnimation.hpp"
#include "components/Animation.hpp"

#define NUM_LEDS 100
CRGB leds[NUM_LEDS];
Animation *anim = new FillAnimation(CRGB::Red);

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, 12, BRG>(leds, NUM_LEDS);
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  anim->updateColorTo(CRGB::Magenta);
  anim->applyTo(leds, NUM_LEDS);
  FastLED.show();
  Serial.println("ON!");
  delay(1000);
  anim->updateColorTo(CRGB::Black);
  anim->applyTo(leds, NUM_LEDS);
  FastLED.show();
  Serial.println("OFF!");
  delay(1000);
}