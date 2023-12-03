#ifndef _SINE_H_
#define _SINE_H_
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