#include "chorus.h"
#include "sine.h"
#include <iostream>

Chorus::Chorus(float dryWet, float modFreq, float modDepth, float samplerate) : Effect(dryWet)
{
    std::cout << "Chorus Constructor" << std::endl;
    this->modDepth = modDepth;
    this->samplerate = samplerate;
    lfo = new Sine(modFreq, samplerate);
    chorusDelay = new Delay(0.f, 1, samplerate, 0.5f);
    setDryWet(dryWet);
}

Chorus::~Chorus()
{
    std::cout << "Chorus Destructor" << std::endl;
    delete lfo;
    lfo = nullptr;

    delete chorusDelay;
    chorusDelay = nullptr;
}

void Chorus::prepare(float samplerate) {
  lfo->prepare(samplerate);
}

void Chorus::applyEffect(const float &input, float &output)
{
    // normalize modulation signal
    float modSignal = lfo->genNextSample() + 1.f;
    modSignal *= 0.5f;
    modSignal *= modDepth;

    // adjust delay according to modulation signal
    chorusDelay->setNumDelaySamples(modSignal * samplerate);
    chorusDelay->applyEffect(input, output);
}

void Chorus::setModFrequency(float modFreq) {
  this->modFreq = modFreq;
  lfo->setFrequency(modFreq);
}

void Chorus::setModDepth(float modDepth){
  this->modDepth = modDepth;
}