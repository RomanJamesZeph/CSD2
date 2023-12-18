#include <iostream>
#include "square.h"

// square constructor
Square::Square(float freq, float amp, float samplerate) : Oscillator(freq, amp, samplerate)
{
  // std::cout << "Square - constructor\n";
}

// square deconstructor
Square::~Square()
{
  // std::cout << "Square - destructor\n";
}

// Method to calculate square wave
// CHATGPT used to create formula
void Square::calculate()
{
    sample = (phase < 0.5) ? amp : -amp;
}
