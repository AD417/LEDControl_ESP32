#include <string.h>
#include <FastLED.h>
// Animation.cpp
#include "Animation.hpp"

Animation::Animation() {
    this->color = CRGB::White;
}

Animation::Animation(CRGB color) {
    this->color = color;
}

Animation::Animation(CRGB::HTMLColorCode color) {
    this->color = color;
}

double Animation::frame() {
    if (frameInterval == 0) return 0;
    unsigned long delta = millis() - this->startTime;
    double out = delta / (double) frameInterval;
    return out;
}

int Animation::frameDiscrete() {
    if (frameInterval == 0) return 0;
    unsigned long delta = millis() - this->startTime;
    int out = delta / frameInterval;
    return out;
}

void Animation::updateColorTo(CRGB newColor) {
    this->color = newColor;
}

bool Animation::isComplete() {
    return false;
}

Animation *Animation::nextAnimation() {
    return this;
}

String Animation::toString() {
    return "an undocumented animation";
}