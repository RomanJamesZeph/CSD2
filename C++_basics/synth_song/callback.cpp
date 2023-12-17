#include "callback.h"

CustomCallback::CustomCallback()
{
  std::cout << "CustomCallback - constructor\n";
}

CustomCallback::~CustomCallback()
{
  std::cout << "CustomCallback - deconstructor\n";
}

double CustomCallback::mtof(float mPitch)
{
  return 440.0 * pow(2.0, (mPitch - 69.0f)/12.0f);
}


void CustomCallback::updatePitch(Melody& melody, Synth& mySynth) {
  float note = melody.getNote();
  double freq = mtof(note);
  std::cout << "next note: " << note << ", has frequency " << freq << std::endl;
  mySynth.setFreq(freq);
}

void CustomCallback::prepare(int rate) 
{
  samplerate = (float) rate;
  mySynth.setSamplerate(samplerate);
  updatePitch(melody,mySynth);
  std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process (AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
  for (int channel = 0; channel < numOutputChannels; ++channel) {
    for (int sample = 0; sample < numFrames; ++sample) {
      outputChannels[channel][sample] = mySynth.getSample() * amplitude;
      mySynth.tick();
      if(frameIndex >= noteDelayFactor * samplerate) 
      {
        // reset frameIndex
        frameIndex = 0;
        updatePitch(melody,mySynth);
      }
      else 
      {
        // increment frameindex
          frameIndex++;
      }
    } // for sample
  } // for channel
} // process()
