#include "waveshaper.h"
#include "wavetablegenerator.h"
#include "math.h"

Waveshaper::Waveshaper(float saturation, float dryWet) : Effect(dryWet), saturation(saturation)
{
  WavetableGenerator::generateSCurve(buffer, BUFFER_SIZE, saturation);
  std::cout << "Waveshaper Constructor" << std::endl;
}

Waveshaper::~Waveshaper()
{
  std::cout << "Waveshaper Destructor" << std::endl;
}

void Waveshaper::applyEffect(const float &input, float &output) 
{
  float sample = input;
  if(sample > 0.99999999f)  sample = 0.99999999f;
  if(sample < -0.99999999f)  sample = -0.99999999f;
  float indexFloat = WavetableGenerator::map(sample, -1.0f, 1.0f, 0.0f, (float) (BUFFER_SIZE - 1));
  //float indexFloat = mapInRange(sample, -1.0f, 1.0f, 0.0f, (float) (BUFFER_SIZE - 1));
  int index = (int) indexFloat;
  output = buffer[index];
  
  // // Sigmoid function
  // output = 2 * 1 / (1 + exp(-saturation*input)) - 1;

  // // Arctan function
  // output = (1/atan(saturation))*atan(saturation*input);
}

void Waveshaper::setSaturation(float saturation)
{
  this->saturation = saturation;
  WavetableGenerator::generateSCurve(buffer, BUFFER_SIZE, saturation);
}