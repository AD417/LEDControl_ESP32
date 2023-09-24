#include <memory>
#include <Arduino.h>
#include <FastLED.h>

#include "Animations/KillAnimation.hpp"
#include "CommandLine/CommandLine.hpp"
#include "CommandLine/colors.hpp"
#include "components/Animation.hpp"
#include "Program.h"

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, 12, BRG>(Program::leds, NUM_LEDS);
  Serial.begin(9600);
  Program::anim = new KillAnimation();
  initColors();
  initCommandLine();
  delay(500);
}

void loop() {
  Program::anim->applyTo(Program::leds, NUM_LEDS);
  FastLED.show();

  if (Program::isInterrupted && Program::anim->isComplete()) {
    Animation * nextAnimation = Program::anim->nextAnimation();
    delete Program::anim;
    Program::anim = nextAnimation;
    Program::isInterrupted = false;
  }

  if (Serial.available()) {
    // Read out string from the serial monitor
    String input = Serial.readStringUntil('\n');

    // Echo the user input
    Serial.print("# ");
    Serial.println(input);

    // Parse the user input into the CLI
    commandLine.parse(input);
  }

  if (commandLine.errored()) {
    CommandError cmdError = commandLine.getError();

    Serial.print("ERROR: ");
    Serial.println(cmdError.toString());

    if (cmdError.hasCommand()) {
      Serial.print("Did you mean \"");
      Serial.print(cmdError.getCommand().toString());
      Serial.println("\"?");
    }
  }

  // Ideally 100fps
  delay(10);
}