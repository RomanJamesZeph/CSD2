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
        Synth (std::string type, int numOsc, float freq = 400, float amp = 1, float samplerate = 44100);
        ~Synth(); 
        void setFreq(float freq);
        float getSample();
        void tick();
        void setSamplerate(float samplerate);
    protected:
        std::string type;
        int numOscillators;
        Oscillator** oscillatorBank;
};

#endif