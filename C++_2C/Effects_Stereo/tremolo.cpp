#include "tremolo.h"

Tremolo::Tremolo(float freq, float modDepth, float dryWet) :
  Effect(dryWet), modDepth(modDepth), sine(freq)
{
  std::cout << "Effect Constructor" << std::endl;
}

Tremolo::~Tremolo() 
{
  std::cout << "Tremolo Destructor" << std::endl;
}

void Tremolo::prepare(float samplerate) 
{
  // NOTE: example, keeping things 'simple', hence no validation
  sine.prepare(samplerate);
}

void Tremolo::applyEffect(const float &input, float &output) {
  // transform sine in range [-1, 1] to range [0, 1]
  float modSignal = sine.genNextSample();
  // apply modDepth
  modSignal *= modDepth;
  modSignal += 1.0 - modDepth;
  // apply modulation signal to input
  // std::cout << sample * modSignal << std::endl;
  output = input * modSignal;
}

void Tremolo::setModFreq(float freq) 
{
  sine.setFrequency(freq);
}

void Tremolo::setModDepth(float modDepth) 
{
  this->modDepth = modDepth;
}