#include <iostream>
#include "square.h"

Square::Square(float freq, float amp, float samplerate) : Oscillator(freq, amp, samplerate)
{
  std::cout << "Square - constructor\n";
}

Square::~Square()
{
  std::cout << "Square - destructor\n";
}

// CHATGPT used to create Square calculate function
void Square::calculate()
{
    sample = (phase < 0.5) ? amp : -amp;
}
