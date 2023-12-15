#include <iostream>
#include "synth.h"

Synth::Synth(float freq, float amp, float samplerate)
{
  std::cout << "Synth - constructor\n";
}

Synth::~Synth()
{
  std::cout << "Synth - deconstructor\n";
}

void Synth::setFreq(float freq)
{
    osc->setFreq(freq);
}

float Synth::getFreq()
{
    return osc->getFreq();
}

void Synth::setAmp(float amp)
{
    osc->setAmp(amp);
}

float Synth::getAmp()
{
    return osc->getAmp();
}

float Synth::getSample()
{
    return osc->getSample();
}

void Synth::tick()
{
    osc->tick();
}

void Synth::calculate()
{
    osc->calculate();
}

void Synth::setSamplerate(float samplerate)
{
    osc->setSamplerate(samplerate);
}

float Synth::getSamplerate()
{
    return osc->getSamplerate();
}