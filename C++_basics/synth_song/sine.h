#ifndef SINE_H
#define SINE_H

#include <iostream>
#include "oscillator.h"

#define SAMPLERATE 44100

class Sine : public Oscillator
{
    public:
        Sine(float freq, float amp);
        ~Sine();
        void tick();
    private:
};

#endif