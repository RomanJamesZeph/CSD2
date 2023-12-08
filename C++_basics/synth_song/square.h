#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
    public:
        Square(float freq, float amp, float samplerate);
        ~Square();
        void calculate();
    private:
};

#endif