#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper(float base, float dryWet) : Effect(dryWet), base(base)
{
  std::cout << "Waveshaper Constructor" << std::endl;
}

Waveshaper::~Waveshaper()
{
  std::cout << "Waveshaper Destructor" << std::endl;
}

void Waveshaper::applyEffect(const float &input, float &output) 
{
    output = (1/atan(base))*atan(base*input);
}