#include "fmsynth.h"

FMSynth::FMSynth(std::string type, int numOsc, float freq, float amp, float samplerate) : Synth(type, numOsc, freq, amp, samplerate), modulationIndex(modulationIndex), modulatorFreq(modulatorFreq)
{
    std::cout << "FMSynth - constructor\n";
}

FMSynth::~FMSynth() 
{
    std::cout << "FMSynth - deconstructor\n";
}

void FMSynth::calculate() {
    // FM synthesis logic
    float modulatorSample = sin(M_PI * 2 * p);

    // Update the phase of the modulator oscillator
    modulatorPhase += 2 * M_PI * modulatorFreq / getSamplerate();
    while (modulatorPhase >= 2 * M_PI) {
        modulatorPhase -= 2 * M_PI;
    }

    // Apply frequency modulation
    setFreq(getFreq() + modulationIndex * modulatorSample);

    // Continue with the rest of the synthesis logic
    Synth::calculate();
}

void FMSynth::setModulationIndex(float modulationIndex) 
{
    this->modulationIndex = modulationIndex;
}

float FMSynth::getModulationIndex()
{
    return modulationIndex;
}

void FMSynth::setModulatorFreq(float modulatorFreq) 
{
    this->modulatorFreq = modulatorFreq;
}

float FMSynth::getModulatorFreq()
{
    return modulatorFreq;
}