#include <memory>
#include <Arduino.h>
#include <FastLED.h>

#include "Animations/AlternatingAnimation.hpp"
#include "Animations/FillAnimation.hpp"
#include "Animations/PulseAnimation.hpp"
#include "Animations/WaveAnimation.hpp"
#include "components/Animation.hpp"
#include "Program.h"

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, 12, BRG>(Program::leds, NUM_LEDS);
  Serial.begin(9600);
  Program::anim = new FillAnimation(CRGB::Black);
  delay(500);
}

void loop() {
  Program::anim->applyTo(Program::leds, NUM_LEDS);
  FastLED.show();

  if (Serial.available()) {
    // NOTE: Must be UNTIL, else it times out waiting for string parsing.
    Serial.readStringUntil('\n');
    Serial.flush();
    Serial.print("Testcat!");
    // Memory safety. Use a unique_ptr when possible; this does for now.
    delete Program::anim;
    Program::anim = new WaveAnimation(CRGB::Red, 500);
  }

  // Ideally 100fps
  delay(10);
}