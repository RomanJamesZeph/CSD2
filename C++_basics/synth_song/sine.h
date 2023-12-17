#ifndef SINE_H
#define SINE_H

#include <iostream>
#include "oscillator.h"
class Sine : public Oscillator
{
    public:
        // constructor and deconstructor
        Sine(float freq, float amp, float samplerate);
        ~Sine();

        void calculate();
    private:
};

#endif