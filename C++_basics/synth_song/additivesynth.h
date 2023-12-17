#ifndef _ADDITIVESYNTH_H_
#define _ADDITIVESYNTH_H_
#include "synth.h"

class AdditiveSynth : public Synth {
public:
    AdditiveSynth(std::string type, int numOscillators, float freq, float amp, float samplerate = 44100);
    ~AdditiveSynth();
};

#endif
