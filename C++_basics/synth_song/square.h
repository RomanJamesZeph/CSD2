#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "oscillator.h"

#define SAMPLERATE 44100

class Square : public Oscillator
{
    public:
        Square(float freq, float amp);
        ~Square();
        void tick();
    private:
};

#endif