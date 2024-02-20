#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "ui.h"
#include "sine.h"
#include "tremolo.h"
#include "delay.h"
#include "waveshaper.h"


class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;
  void initializeTremolo();
  void initializeDelay();
  void initializeWaveshaper();

private:
  float samplerate = 44100;
  Sine sine = Sine(400, samplerate);
  Tremolo tremolo = Tremolo(6, 1);
  Waveshaper waveshaper;
  Delay delay;

  std::string effectOptions[3] = {"Tremolo", "Delay", "Waveshaper"};
  int numEffectOptions = 3;
  int effectTypeSelection;

  UI console_ui;
};

#endif //CALLBACK_H
