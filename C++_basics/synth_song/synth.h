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
        // constructor and deconstructor
        Synth (int numOscillators);
        ~Synth();

        void addOscillator(int index, std::string waveType, float freq, float amp, float samplerate);

        //getters and setters
        virtual void setFreq(float freq);
        virtual float getSample() = 0;

        // go to next sample
        void tick();
        
    protected:
        // number of oscillators
        int numOscillators;
        
        // creates an oscillator bank to store oscillators
        Oscillator** oscillatorBank;
};

#endif