#include <iostream>
#include "sine.h"

// Sine constructor
Sine::Sine(float freq, float amp, float samplerate) : Oscillator(freq, amp, samplerate)
{
  // std::cout << "Sine - constructor\n";
}

// Sine deconstructor
Sine::~Sine()
{
  // std::cout << "Sine - destructor\n";
}

// Method to calculate sine wave
void Sine::calculate()
{
    sample = amp * sin(M_PI * 2 * phase);
}