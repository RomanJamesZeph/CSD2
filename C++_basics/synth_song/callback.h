#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "synth.h"
#include "oscillator.h"
#include "sine.h"
#include "triangle.h"
#include "square.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate = 400;
  Synth synth = Synth(200, 1, samplerate);
};

#endif //CALLBACK_H