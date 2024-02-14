#include <iostream>
#include "callback.h"
#include "oscillator.h"
#include "sine.h"
#include "tremolo.h"


void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
    tremolo.prepare(rate);
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
  float sample;
  for (int channel = 0u; channel < numOutputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++) {
      sample = tremolo.processFrame(inputChannels[channel][i]);
      std::cout << sample << std::endl;
      outputChannels[channel][i] = sample;
    }
  }
}

