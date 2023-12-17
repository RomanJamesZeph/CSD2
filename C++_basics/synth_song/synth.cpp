#include <iostream>
#include "synth.h"

Synth::Synth(std::string type, int numOscillators, float freq, float amp, float samplerate) : type(type), numOscillators(numOscillators)
{
    std::cout << "Synth - constructor\n";
}

Synth::~Synth()
{
    for (int i = 0; i < numOscillators; ++i) {
        delete oscillatorBank[i];
    }
    delete[] oscillatorBank;
    std::cout << "Synth - deconstructor\n";
}

void Synth::setFreq(float freq)
{
    for (int i = 0; i < numOscillators; ++i) {
        oscillatorBank[i]->setFreq(freq);
        std::cout << "Synth - setting frequenty\n";
    }
}

float Synth::getSample()
{
    float sample = 0.0f;
    for (int i = 0; i < numOscillators; ++i) {
        sample += oscillatorBank[i]->getSample();
        std::cout << "Synth - getting sample\n";
    }
    return sample;
}

void Synth::tick()
{
    for (int i = 0; i < numOscillators; ++i) {
        oscillatorBank[i]->tick();
        std::cout << "Synth - ticking\n";
    }
}

void Synth::setSamplerate(float samplerate)
{
    for (int i = 0; i < numOscillators; ++i) {
        oscillatorBank[i]->setSamplerate(samplerate);
        std::cout << "Synth - setting samplerate\n";
    }
}