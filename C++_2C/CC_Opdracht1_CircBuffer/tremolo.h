#pragma once

#include <iostream>
#include "sine.h"
#include "effect.h"

class Tremolo : public Effect
{
public:
  Tremolo(float freq = 1.0f, float modDepth = 1.0f, float dryWet = 1.0);
  ~Tremolo();

  void prepare(float samplerate);

  // setters and getters
  void setModFreq(float freq);

private:
  float modDepth;
  Sine sine;
  float applyEffect(float sample) override;
};
