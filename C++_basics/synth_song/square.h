#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
    public:
        // constructor and deconstructor
        Square(float freq, float amp, float samplerate);
        ~Square();
        
        void calculate();
    private:
};

#endif