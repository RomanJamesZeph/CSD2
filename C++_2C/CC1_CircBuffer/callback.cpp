#include "callback.h"


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
      // tremolo.processFrame(sine.genNextSample(),  sample);
      delay.processFrame(sine.genNextSample(),  outputChannels[channel][i]);
    }
  }
}

