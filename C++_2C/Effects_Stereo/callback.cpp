#include "callback.h"

void CustomCallback::prepare(int rate) 
{
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
}


void CustomCallback::process(AudioBuffer buffer) 
{
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
  float sample;
  // for (int channel = 0u; channel < numOutputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++){
      chorus.processFrame(inputChannels[0][i],  outputChannels[0][i]);
      chorus.processFrame(inputChannels[0][i],  outputChannels[1][i]);
    }
  // }
}