#include <iostream>
#include "triangle.h"

// Triangle constructor
Triangle::Triangle(float freq, float amp, float samplerate) : Oscillator(freq, amp, samplerate)
{
  std::cout << "Triangle - constructor\n";
}

// Triangle deconstructor
Triangle::~Triangle()
{
  std::cout << "Triangle - destructor\n";
}

// method to calculate triangle wave
// CHATGPT used to create formula
void Triangle::calculate()
{
    sample = 2 * amp * (phase - floor(phase + 0.5));
}