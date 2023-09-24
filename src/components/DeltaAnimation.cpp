#include "DeltaAnimation.hpp"

#include <FastLED.h>

DeltaAnimation::DeltaAnimation(
    Animation * mainAnimation,
    Animation * otherAnimation,
    unsigned long transitionInterval
) : Animation() {

    this->transitionInterval = transitionInterval;
    this->endTime = this->startTime + transitionInterval;
    this->mainAnimation = mainAnimation;
    this->otherAnimation = otherAnimation;
};

DeltaAnimation::~DeltaAnimation() {
    delete mainAnimation;
    // Ensure that otherAnimation is safe somewhere.
}

void DeltaAnimation::updateColorTo(CRGB newColor) {
    this->otherAnimation->updateColorTo(newColor);
}

double DeltaAnimation::transitionPercent() {
    unsigned long delta = millis() - this->startTime;
    return (double) delta / transitionInterval;
}

bool DeltaAnimation::isComplete() {
    return this->stopNow || millis() > this->endTime;
}

void DeltaAnimation::abort() {
    this->stopNow = true;
}

Animation *DeltaAnimation::nextAnimation() {
    return otherAnimation;
}

void DeltaAnimation::applyTo(CRGB strip[], int len) {
    CRGB otherStrip[len];

    this->mainAnimation->applyTo(strip, len);
    this->otherAnimation->applyTo(otherStrip, len);

    this->blend(strip, otherStrip, len);
}


