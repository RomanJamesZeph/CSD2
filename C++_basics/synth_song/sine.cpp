#include <iostream>
#include "sine.h"
#pragma GCC diagnostic ignored "-Wc++11-extensions"

Sine::Sine(float freq, float amp) : Oscillator(freq, amp)
{
  std::cout << "Sine - constructor\n";
}

Sine::~Sine()
{
  std::cout << "Sine - destructor\n";
}

void Sine::tick()
{
    phase += freq / SAMPLERATE;
    sample = amp * sin(M_PI * 2 * phase);
}