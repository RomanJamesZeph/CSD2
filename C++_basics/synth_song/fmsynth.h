#ifndef _FMSYNTH_H_
#define _FMSYNTH_H_
#include "synth.h"

// chatGPT used to create frequenty modulation variables

class FMSynth : public Synth 
{
    public:
        FMSynth(std::string type, int numOsc, float freq, float amp, float samplerate = 44100);
        ~FMSynth();
        void calculate();
        void setModulationIndex(float modulationIndex);
        float getModulationIndex();
        void setModulatorFreq(float ModulatorFreq);
        float getModulatorFreq();
    
    protected:
        float modulationIndex;
        float modulatorFreq;
};

#endif