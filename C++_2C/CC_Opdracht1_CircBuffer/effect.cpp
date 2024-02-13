#include "effect.h"

Effect::Effect(float dryWet)
{
  setDryWet(dryWet);
  std::cout << "Effect - constructor\n";
}

Effect::~Effect()
{
  std::cout << "Effect - destructor\n";
}

float Effect::processFrame(float input)
{
  float output = applyEffect(input);

  // apply dry wet
  float dryOutput = input * wet;
  float wetOutput = output * dry;
  output = wetOutput + dryOutput;

  return output;
}

void Effect::setDryWet(float dryWet)
{
  if (dryWet > 0.0f && dryWet < 1.0f)
  {
    wet = dryWet;
    dry = 1.0f - dryWet;
  } 
  else 
  {
    std::cout << "Error - Wet/Dry wrong value\n";
  }
}

float Effect::getDryWet()
{
  return wet;
}