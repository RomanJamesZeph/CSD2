#include <iostream>
#include "oscillator.h"

// Oscillator::Oscillator() : Oscillator (600, 0, 44100) //default values
// {

// }

Oscillator::Oscillator(float freq, float amp, float samplerate) : freq(freq), amp(amp), samplerate(samplerate)
{
    std::cout << "Oscillator - constructor\n";
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

void Oscillator::tick()
{
    phase += freq / samplerate;
    if(phase > 1) phase -= 1.0;
    calculate();
}

void Oscillator::setSamplerate(float samplerate) 
{
    this -> samplerate = samplerate;
}

float Oscillator::getSamplerate()
{
    return samplerate;
}