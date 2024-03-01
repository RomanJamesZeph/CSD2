#include "chorus.h"
#include "sine.h"
#include <iostream>

Chorus::Chorus(float dryWet, float modFreq, float modDepth, float samplerate) : Effect(dryWet), lfo(modFreq)
{
    std::cout << "Chorus Constructor" << std::endl;
    this->modDepth = modDepth;
    this->samplerate = samplerate;
}

Chorus::~Chorus()
{
    std::cout << "Chorus Destructor" << std::endl;
}

void Chorus::prepare(float samplerate) {
  lfo.prepare(samplerate);
}

void Chorus::applyEffect(const float &input, float &output)
{
    float modSignal = lfo.genNextSample() + 1.f;
    modSignal *= 0.5f;
    modSignal *= modDepth;
    std::cout << "Chorus modsignal: " << modSignal << std::endl;

    chorusDelay.setNumDelaySamples(modSignal * samplerate);
    std::cout << "Chorus input: " << input << std::endl;
    chorusDelay.applyEffect(input, output);
}

void Chorus::setModFrequency(float modFreq) {
  this->modFreq = modFreq;
  lfo.setFrequency(modFreq);
}

void Chorus::setModDepth(float modDepth){
  this->modDepth = modDepth;
}