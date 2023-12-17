#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "oscillator.h"

class Triangle : public Oscillator
{
    public:
        // constructor and deconstructor
        Triangle(float freq, float amp, float samplerate);
        ~Triangle();
        
        void calculate();
    private:
};

#endif