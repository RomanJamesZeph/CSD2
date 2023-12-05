#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "oscillator.h"

#define SAMPLERATE 44100

class Triangle : public Oscillator
{
    public:
        Triangle(float freq, float amp);
        ~Triangle();
        void tick();
    private:
};

#endif