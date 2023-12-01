#include <iostream>
#include "sine.h"
#pragma GCC diagnostic ignored "-Wc++11-extensions"

Sine::Sine(float frequency) 
{
    this->frequency = frequency;
}

Sine::~Sine()
{

}

float Sine::getSample()
{
    return sample;
}

void Sine::tick()
{
    phase += frequency / SAMPLERATE;
    sample = sin(M_PI * 2 * phase);
}

void Sine::setFrequency(float frequency)
{
    this->frequency = frequency;
}

float Sine::getFrequency()
{
    return frequency;
}