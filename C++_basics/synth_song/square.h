#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
    public:
        Square(float freq, float amp);
        ~Square();
        void calculate();
    private:
};

#endif