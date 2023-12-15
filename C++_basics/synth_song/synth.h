#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "triangle.h"
#include "square.h"

class Synth
{
    public:
        Synth(float freq, float amp, float samplerate = 44100);
        ~Synth(); 

        void setFreq(float freq);
        float getFreq();
        void setAmp(float amp);
        float getAmp();
        float getSample();
        void tick();
        void calculate();
        void setSamplerate(float samplerate);
        float getSamplerate();
    private:
        Oscillator* osc = new Square(1000, 1, 44100);
};

#endif