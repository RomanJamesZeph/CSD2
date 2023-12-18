#ifndef _FM_SYNTH_H_
#define _FM_SYNTH_H_

#include "synth.h"

class FMSynth : public Synth
{
    public:
        // Constructor and destructor
        FMSynth(int numCarriers, int numModulators);
        ~FMSynth();

        // FM-specific methods
        void addModulator(int index, std::string waveType, float freq, float amp, float modIndex, float samplerate);

        // Override or extend methods
        float getSample();

    protected:
        // Additional properties for FM synthesis
        int numModulators;
        Oscillator** modulatorBank;
        float* modulationIndices;
};

#endif
