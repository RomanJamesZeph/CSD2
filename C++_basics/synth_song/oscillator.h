#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

class Oscillator
{
    public:
        //constructor and deconstructor:
        Oscillator();
        Oscillator(float freq, float amp, float samplerate = 44100);
        virtual ~Oscillator();

        // setter and getters:
        void setFreq(float freq);
        float getFreq();
        void setAmp(float amp);
        float getAmp();
        float getSample();

        // tick method:
        void tick();

        // calculate method (gets skipped):
        virtual void calculate() = 0;

    protected:
        float freq;
        float amp;
        float phase = 0;
        float sample = 0;
        float samplerate;
};

#endif