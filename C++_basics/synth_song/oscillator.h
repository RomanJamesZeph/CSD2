#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

class Oscillator
{
    public:
        // Oscillator();
        Oscillator(float freq, float amp, float samplerate = 44100);
        virtual ~Oscillator();
        void setFreq(float freq);
        float getFreq();
        void setAmp(float amp);
        float getAmp();
        float getSample();
        void tick();
        virtual void calculate() = 0;
        void setSamplerate(float samplerate);
        float getSamplerate();

    protected:
        float freq;
        float amp;
        float phase = 0;
        float sample = 0;
        float samplerate;
};

#endif