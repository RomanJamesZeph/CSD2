#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper(float saturation, float dryWet) : Effect(dryWet), saturation(saturation)
{
  std::cout << "Waveshaper Constructor" << std::endl;
}

Waveshaper::~Waveshaper()
{
  std::cout << "Waveshaper Destructor" << std::endl;
}

void Waveshaper::applyEffect(const float &input, float &output) 
{
  // Sigmoid function
  output = 2 * 1 / (1 + exp(-saturation*input)) - 1;

  // Arctan function
  output = (1/atan(saturation))*atan(saturation*input);
}

void Waveshaper::setSaturation(float saturation)
{
  this->saturation = saturation;
}