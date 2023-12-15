#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "oscillator.h"

class Triangle : public Oscillator
{
    public:
        Triangle(float freq, float amp, float samplerate);
        ~Triangle();
        void calculate();
    private:
};

#endif