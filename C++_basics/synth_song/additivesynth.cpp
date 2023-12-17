#include "additivesynth.h"

AdditiveSynth::AdditiveSynth(int numOscillators)
    : Synth(numOscillators) 
{
    std::cout << "AdditiveSynth - constructor\n";
}

AdditiveSynth::~AdditiveSynth() 
{
    std::cout << "AdditiveSynth - deconstructor\n";
}