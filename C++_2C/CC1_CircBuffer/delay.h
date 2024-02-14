#pragma once
#include <iostream>
#include "effect.h"

class Delay : public Effect
{
    public:
        Delay(int delaySamples, int maxDelaySamples, 
        float feedback = 0.0f, float dryWet = 1.0f);
        ~Delay();

        void prepare(float samplerate) override;

        void setFeedback(float feedback);
        float getFeedback();
    
    private:
        float feedback;
        float buffer[44100];
        int readH;
        int writeH;

        float applyEffect(float sample) override;
        Delay(){};
};