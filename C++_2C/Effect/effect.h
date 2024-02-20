#pragma once
#include "ui.h"
class Effect
{
public:
  Effect(float dryWet = 1.0);
  virtual ~Effect();

  virtual void prepare(float samplerate) { }

  // process frame
  void processFrame(const float &input, float &output);

  // returns the last outputted sample
  float getSample();

  void setDryWet(float dryWet);

protected:
  // pure virtual method
  virtual void applyEffect(const float &input, float &output) = 0;

private:
  float dryWet;
  float wetDry;
  float m_sample;
};
