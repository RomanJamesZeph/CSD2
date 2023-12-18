#include <iostream>
#include "synth.h"

// synth constructor
Synth::Synth(int numOscillators) : numOscillators(numOscillators)
{
    // Creates pointers to oscillators in oscillator bank
    oscillatorBank = new Oscillator* [numOscillators];
    // std::cout << "Synth - constructor\n";
}

// synth deconstructor
Synth::~Synth()
{
    // deletes oscillators in oscillator Bank
    for (int i = 0; i < numOscillators; ++i) {
        delete oscillatorBank[i];
    }
    // deletes oscillator Bank
    delete[] oscillatorBank;
    // std::cout << "Synth - deconstructor\n";
}

// method to add different waveforms to the oscillator bank
void Synth::addOscillator(int index, std::string waveType, float freq, float amp, float samplerate)
{
    if (waveType == "sine")
    {
        oscillatorBank[index] = new Sine (freq, amp, samplerate);
    }
    else if (waveType == "square")
    {
        oscillatorBank[index] = new Square (freq, amp, samplerate);
    }
    else if (waveType == "triangle")
    {
        oscillatorBank[index] = new Triangle (freq, amp, samplerate);
    }
    std::cout << "added " << waveType << " with freq: " << freq << " and amp: " << amp << std::endl;
    std::cout << std::endl;
}

// method to set frequenty for each oscillator in oscillator bank
void Synth::setFreq(float freq)
{
    for (int i = 0; i < numOscillators; ++i) {
        oscillatorBank[i]->setFreq(freq);
        // std::cout << "Synth - setting frequenty\n";
    }
}

// method to get sample for each oscillator in oscillator bank
float Synth::getSample()
{
    float sample = 0.0f;
    for (int i = 0; i < numOscillators; ++i) {
        sample += oscillatorBank[i]->getSample();
        std::cout << "Synth - getting sample\n";
    }
    return sample;
}

// method to go to the next sample for each oscillator in the oscillator bank
void Synth::tick()
{
    for (int i = 0; i < numOscillators; ++i) {
        oscillatorBank[i]->tick();
        // std::cout << "Synth - ticking\n";
    }
}