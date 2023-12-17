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
#include "ui.h"

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
    int numberOscillators = 4;
    float amplitude = 0.5;
    int frameIndex = 0;
    double noteDelayFactor = 0.05;
    std::string waveFormOptions[3] = {"sine", "square", "triangle"};
    int numWaveFormOptions = 3;
    UI console_ui;
    AdditiveSynth mySynth;
    Melody melody;
};

#endif //CALLBACK_H
