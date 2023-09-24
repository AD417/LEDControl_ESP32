

#include "Animation.hpp"

class DeltaAnimation : public Animation 
{
public: 
    DeltaAnimation(
        Animation * mainAnimation, 
        Animation * otherAnimation, 
        unsigned long transitionInterval
    );

    ~DeltaAnimation();

    void updateColorTo(CRGB newColor) override;
    double transitionPercent();
    bool isComplete() override;
    void abort();
    Animation *nextAnimation() override;
    void applyTo(CRGB strip[], int len) override;

protected:
    unsigned long transitionInterval;
    unsigned long endTime;
    Animation * mainAnimation;
    Animation * otherAnimation;
    bool stopNow = false;

    virtual void blend(CRGB mainStrip[], CRGB otherStrip[], int len) = 0;
};