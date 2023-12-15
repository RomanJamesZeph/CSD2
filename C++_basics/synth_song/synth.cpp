#include <iostream>
#include "synth.h"

Synth::Synth(float freq, float amp, float samplerate)

{
    oscillatorBank[0] = new Triangle(300, 1, 44100);
    oscillatorBank[1] = new Sine(500, 1, 44100);
    std::cout << "Synth - constructor\n";
}

Synth::~Synth()
{
    delete oscillatorBank[0];
    delete oscillatorBank[1];
    std::cout << "Synth - deconstructor\n";
}

void Synth::setFreq(float freq)
{
    for (int i = 0; i < 2; ++i) {
        oscillatorBank[i]->setFreq(freq);
    }
}

float Synth::getFreq()
{
    return oscillatorBank[0]->getFreq();
}

void Synth::setAmp(float amp)
{
    for (int i = 0; i < 2; ++i) {
        oscillatorBank[i]->setAmp(amp);
    }
}

float Synth::getAmp()
{
    return oscillatorBank[0]->getAmp();
}

float Synth::getSample()
{
    float sample = 0.0f;
    for (int i = 0; i < 2; ++i) {
        sample += oscillatorBank[i]->getSample();
    }
    return sample;
}

void Synth::tick()
{
    for (int i = 0; i < 2; ++i) {
        oscillatorBank[i]->tick();
    }
}

void Synth::calculate()
{
    for (int i = 0; i < 2; ++i) {
        oscillatorBank[i]->calculate();
    }
}

void Synth::setSamplerate(float samplerate)
{
    for (int i = 0; i < 2; ++i) {
        oscillatorBank[i]->setSamplerate(samplerate);
    }
}

float Synth::getSamplerate()
{
    return oscillatorBank[0]->getSamplerate();
}