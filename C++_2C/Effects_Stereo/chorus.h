#pragma once
#include "effect.h"
#include "sine.h"
#include "delay.h"
class Chorus : public Effect
{
    public:
        Chorus(float dryWet = 0.5f, float modFreq = 0.5f, float modDepth = 0.5f, float samplerate = 44100);
        ~Chorus();

        void prepare(float samplerate) override;
        void applyEffect(const float &input, float &output) override;
        
        void setModFrequency(float modFreq);
        void setModDepth(float modDepth);
    private:
        Sine lfo;
        Delay chorusDelay;

        float modFreq;
        float modDepth;
        float samplerate;
};