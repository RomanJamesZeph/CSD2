#include "callback.h"

void CustomCallback::prepare(int rate) 
{
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
    effectTypeSelection = console_ui.retrieveUserSelection(effectOptions, numEffectOptions);

    if (effectTypeSelection == 0)
    {
      initializeTremolo();
    }
    else if (effectTypeSelection == 1)
    {
      initializeDelay();
    }
    else if (effectTypeSelection == 2)
    {
      initializeWaveshaper();
    }
}

void CustomCallback::initializeTremolo()
{
  float dryWet = console_ui.retrieveValueInRangeFloat("Dry Wet:", 0, 1);
  std::cout << "Drywet: " << dryWet << std::endl;

  float modFreq = console_ui.retrieveValueInRangeFloat("ModFreq:", 1, 20);
  std::cout << "modFreq: " << modFreq << std::endl;

  float modDepth = console_ui.retrieveValueInRangeFloat("ModDepth:", 0, 1);
  std::cout << "modDepth: " << modDepth << std::endl;

  tremolo.setDryWet(dryWet);
  tremolo.setModFreq(modFreq);
  tremolo.setModDepth(modDepth);
}

void CustomCallback::initializeDelay()
{
  float dryWet = console_ui.retrieveValueInRangeFloat("Dry Wet:", 0, 1);
  std::cout << "Drywet: " << dryWet << std::endl;

  int numDelaySamples = console_ui.retrieveValueInRangeInt("numDelaySamples:", 0, 2048);
  std::cout << "numDelaySamples: " << numDelaySamples << std::endl;

  float feedback = console_ui.retrieveValueInRangeFloat("Feedback:", 0, 1);
  std::cout << "Feedback: " << dryWet << std::endl;

  delay.setDryWet(dryWet);
  delay.setNumDelaySamples(numDelaySamples);
  delay.setFeedback(feedback);
}

void CustomCallback::initializeWaveshaper()
{
  float dryWet = console_ui.retrieveValueInRangeFloat("Dry Wet:", 0, 1);
  std::cout << "Drywet: " << dryWet << std::endl;

  float saturation = console_ui.retrieveValueInRangeFloat("saturation:", 0, 10);
  std::cout << "Saturation: " << saturation << std::endl;

  waveshaper.setDryWet(dryWet);
  waveshaper.setSaturation(saturation);
}


void CustomCallback::process(AudioBuffer buffer) 
{
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
  float sample;
  for (int channel = 0u; channel < numOutputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++){
      if (effectTypeSelection == 0)
      {
        // std::cout << "Tremolo";
        tremolo.processFrame(inputChannels[channel][i],  outputChannels[channel][i]);
      }
      else if (effectTypeSelection == 1)
      {
        // std::cout << "Delay";
        delay.processFrame(inputChannels[channel][i],  outputChannels[channel][i]);
      }
      else if (effectTypeSelection == 2)
      {
        // std::cout << "Waveshaper";
        waveshaper.processFrame(sine.genNextSample(),  outputChannels[channel][i]);
      }
    }
  }
}