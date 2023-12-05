#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>
#define SAMPLERATE 44100

class Oscillator
{
    public:
        Oscillator();
        Oscillator(float freq, float amp);
        ~Oscillator();

        void setFreq(float freq);
        float getFreq();
        void setAmp(float amp);
        float getAmp();
        float getSample();
        void tick();
        virtual void calculate() = 0;

    protected:
        float freq;
        float amp;
        float phase = 0;
        float sample = 0;
};

#endif