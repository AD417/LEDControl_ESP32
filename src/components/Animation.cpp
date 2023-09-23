#include <string.h>
#include <FastLED.h>
// Animation.cpp
#include "Animation.hpp"

Animation::Animation(CRGB color, unsigned long frameInterval) {
    this->color = color;
    this-> frameInterval = frameInterval;
}

double Animation::frame() {
    if (frameInterval == 0) return 0;
    unsigned long delta = millis() - this->start_time;
    double out = delta / (double) frameInterval;
    return out;
}

int Animation::frameDiscrete() {
    if (frameInterval == 0) return 0;
    unsigned long delta = millis() - this->start_time;
    int out = delta / frameInterval;
    return out;
}

void Animation::updateColorTo(CRGB new_color) {
    this->color = new_color;
}

bool Animation::isComplete() {
    return false;
}

Animation *Animation::nextAnimation() {
    return this;
}

String Animation::toString() {
    return "An undocumented animation";
}