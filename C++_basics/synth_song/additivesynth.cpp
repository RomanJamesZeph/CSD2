#include "additivesynth.h"

// Additive synth constructor
AdditiveSynth::AdditiveSynth(int numPartials) : Synth(numPartials)
{
    // std::cout << "AdditiveSynth - constructor\n";
}

// Additive synth deconstructor
AdditiveSynth::~AdditiveSynth() 
{
    // std::cout << "AdditiveSynth - deconstructor\n";
}

// method to get sample for each oscillator in oscillator bank
float AdditiveSynth::getSample()
{
    float sample = 0.0f;
    for (int i = 0; i < numOscillators; ++i) {
        sample += oscillatorBank[i]->getSample();
    }
    return sample;
}