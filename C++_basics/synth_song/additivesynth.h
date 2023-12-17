#ifndef _ADDITIVESYNTH_H_
#define _ADDITIVESYNTH_H_
#include "synth.h"

class AdditiveSynth : public Synth {
public:
    AdditiveSynth(int numOscillators);
    ~AdditiveSynth();
};

#endif
