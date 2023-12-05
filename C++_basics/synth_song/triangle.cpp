#include <iostream>
#include "triangle.h"

Triangle::Triangle(float freq, float amp) : Oscillator(freq, amp)
{
  std::cout << "Triangle - constructor\n";
}

Triangle::~Triangle()
{
  std::cout << "Triangle - destructor\n";
}

// CHATGPT used to create triangle tick function
void Triangle::tick()
{
    phase += freq / SAMPLERATE;
    sample = 2 * amp * (phase - floor(phase + 0.5));
}