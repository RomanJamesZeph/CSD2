#include <iostream>
#include "oscillator.h"

// delegating constructor
Oscillator::Oscillator() : Oscillator (600, 0, 44100) //default values
{

}

// initializer list
Oscillator::Oscillator(float freq, float amp, float samplerate) : freq(freq), amp(amp), samplerate(samplerate)
{
    // std::cout << "Oscillator - constructor\n";
}

Oscillator::~Oscillator()
{
    // std::cout << "Oscillator - deconstructor\n";
}

// method to set frequenty
void Oscillator::setFreq(float freq)
{
    if(freq > 0 && freq < 22050) {
        this->freq = freq;
    } else {
        std::cout << "The frequency value is incorrect" << " please present a value in the interval [0, 22049]\n";
  }
}

// method to get frequenty
float Oscillator::getFreq()
{
    return freq;
}

// method to set amp
void Oscillator::setAmp(float amp)
{
    this->amp = amp;
}

// method to get amp
float Oscillator::getAmp()
{
    return amp;
}

// method to get sample
float Oscillator::getSample()
{
    return sample;
}

// method to go to the next sample
void Oscillator::tick()
{
    // increment the phase to allow calculation of next sample
    phase += freq / samplerate;
    // wrap the phase to interval [0, 1]
    if(phase > 1) phase -= 1.0;
     // calculate sample for the incremented phase
    calculate();
}