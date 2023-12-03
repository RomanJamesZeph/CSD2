#include <iostream>
#include "triangular.h"

Triangular::Triangular(float freq, float amp) : Oscillator(freq, amp)
{
  std::cout << "Triangular - constructor\n";
}

Triangular::~Triangular()
{
  std::cout << "Triangular - destructor\n";
}

void Triangular::tick()
{
    phase += freq / SAMPLERATE;
    sample = 2 * amp * (phase - floor(phase + 0.5));
}