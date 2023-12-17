#include "additivesynth.h"

// Additive synth constructor
AdditiveSynth::AdditiveSynth(int numOscillators)
    : Synth(numOscillators) 
{
    std::cout << "AdditiveSynth - constructor\n";
}

// Additive synth deconstructor
AdditiveSynth::~AdditiveSynth() 
{
    std::cout << "AdditiveSynth - deconstructor\n";
}