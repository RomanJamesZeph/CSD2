#ifndef TRIANGULAR_H
#define TRIANGULAR_H

#include <iostream>
#include "oscillator.h"

#define SAMPLERATE 44100

class Triangular : public Oscillator
{
    public:
        Triangular(float freq, float amp);
        ~Triangular();
        void tick();
    private:
};

#endif