#include <iostream>
#include "square.h"

Square::Square(float freq, float amp) : Oscillator(freq, amp)
{
  std::cout << "Square - constructor\n";
}

Square::~Square()
{
  std::cout << "Square - destructor\n";
}

void Square::tick()
{
    phase += freq / SAMPLERATE;
    sample = (phase < 0.5) ? amp : -amp;
}
