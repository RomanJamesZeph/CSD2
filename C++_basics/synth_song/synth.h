#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "triangle.h"
#include "square.h"
#include "ui.h"

class Synth
{
    public:
        Synth (int numOsc);
        ~Synth();
        void addOscillator(int index, std::string waveType, float freq, float amp, float samplerate);
        void setFreq(float freq);
        float getSample();
        void tick();
        void setSamplerate(float samplerate);
    protected:
        int numOscillators;
        Oscillator** oscillatorBank;
};

#endif