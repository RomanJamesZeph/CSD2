#pragma once
#include "effect.h"
#include "oscillator.h"
#include "delay.h"

// made with help from Pier Woudsta
class Chorus : public Effect
{
    public:
        Chorus(float dryWet = 0.5f, float modFreq = 0.5f, float modDepth = 0.002f, float samplerate = 44100);
        ~Chorus();

        void prepare(float samplerate) override;
        void applyEffect(const float &input, float &output) override;
        
        void setModFrequency(float modFreq);
        void setModDepth(float modDepth);
    private:
        Oscillator *lfo;
        Delay *chorusDelay;

        float modFreq;
        float modDepth;
        float samplerate;
};