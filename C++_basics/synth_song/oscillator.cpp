#include <iostream>
#include "oscillator.h"

Oscillator::Oscillator() : Oscillator (220, 0) //default values
{

}

Oscillator::Oscillator(float freq, float amp) : freq(freq), amp(amp)
{

}

Oscillator::~Oscillator()
{

}

void Oscillator::setFreq(float freq)
{
    this->freq = freq;
}

float Oscillator::getFreq()
{
    return freq;
}

void Oscillator::setAmp(float amp)
{
    this->amp = amp;
}

float Oscillator::getAmp()
{
    return amp;
}

float Oscillator::getSample()
{
    return sample;
}
