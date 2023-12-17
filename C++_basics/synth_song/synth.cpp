#include <iostream>
#include "synth.h"

Synth::Synth(int numOscillators) : numOscillators(numOscillators)
{
    oscillatorBank = new Oscillator* [numOscillators];
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

void Synth::addOscillator(int index, std::string waveType, float freq, float amp, float samplerate)
{
    if (waveType == "sine")
    {
        oscillatorBank[index] = new Sine (freq, amp, samplerate);
        std::cout << "added new sine with freq: " << freq << std::endl;
    }
    else if (waveType == "square")
    {
        oscillatorBank[index] = new Square (freq, amp, samplerate);
        std::cout << "added new square with freq " << freq << std::endl;
    }
    else if (waveType == "triangle")
    {
        oscillatorBank[index] = new Triangle (freq, amp, samplerate);
        std::cout << "added new triangle with freq: " << freq << std::endl;
    }
}

void Synth::setFreq(float freq)
{
    for (int i = 0; i < numOscillators; ++i) {
        oscillatorBank[i]->setFreq(freq);
        // std::cout << "Synth - setting frequenty\n";
    }
}

float Synth::getSample()
{
    float sample = 0.0f;
    for (int i = 0; i < numOscillators; ++i) {
        sample += oscillatorBank[i]->getSample();
        // std::cout << "Synth - getting sample\n";
    }
    return sample;
}

void Synth::tick()
{
    for (int i = 0; i < numOscillators; ++i) {
        oscillatorBank[i]->tick();
        // std::cout << "Synth - ticking\n";
    }
}

void Synth::setSamplerate(float samplerate)
{
    for (int i = 0; i < numOscillators; ++i) {
        oscillatorBank[i]->setSamplerate(samplerate);
        std::cout << "Synth - setting samplerate\n";
    }
}