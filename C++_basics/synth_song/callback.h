#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "synth.h"
#include "oscillator.h"
#include "sine.h"
#include "triangle.h"
#include "square.h"
#include "melody.h"
#include "additivesynth.h"
#include "fmsynth.h"

class CustomCallback : public AudioCallback 
{
  public:
    CustomCallback();
    ~CustomCallback();
    double mtof(float mPitch);
    void updatePitch(Melody& melody, Synth& mySynth);
    void prepare(int rate) override;
    void process(AudioBuffer buffer) override;

  private:
    float samplerate = 44100;
    int numberOscillators = 1;
    std::string type = "random";
    float amplitude = 0.5;
    int frameIndex = 0;
    double noteDelayFactor=0.05;
    AdditiveSynth mySynth = AdditiveSynth(type, numberOscillators, 500, amplitude, samplerate);
    // FMSynth mySynth = FMSynth(type, numberOscillators, 500, amplitude, samplerate);
    Melody melody;
};

#endif //CALLBACK_H
