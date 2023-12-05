#include <iostream>
#include "sine.h"

Sine::Sine(float freq, float amp) : Oscillator(freq, amp)
{
  std::cout << "Sine - constructor\n";
}

Sine::~Sine()
{
  std::cout << "Sine - destructor\n";
}

void Sine::calculate()
{
    sample = amp * sin(M_PI * 2 * phase);
}