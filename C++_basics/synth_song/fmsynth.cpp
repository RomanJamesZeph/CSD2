#include "fmsynth.h"

FMSynth::FMSynth(int numCarriers, int numModulators) 
    : Synth(numCarriers), numModulators(numModulators)
{
    modulatorBank = new Oscillator*[numModulators];
    modulationIndices = new float[numModulators];
    // std::cout << "FMSynth - constructor\n";
}

FMSynth::~FMSynth()
{
    for (int i = 0; i < numModulators; ++i) {
        delete modulatorBank[i];
    }
    delete[] modulatorBank;
    delete[] modulationIndices;
    // std::cout << "FMSynth - deconstructor\n";
}

void FMSynth::addModulator(int index, std::string waveType, float freq, float amp, float modIndex, float samplerate)
{
    // Create modulator oscillator based on waveType
    if (waveType == "sine") {
        modulatorBank[index] = new Sine(freq, amp, samplerate);
    } else if (waveType == "square") {
        modulatorBank[index] = new Square(freq, amp, samplerate);
    } else if (waveType == "triangle") {
        modulatorBank[index] = new Triangle(freq, amp, samplerate);
    }

    // Set the modulation index for this modulator
    modulationIndices[index] = modIndex;

    std::cout << "Added new " << waveType << " modulator with freq: " << freq << " and modulation index: " << modIndex << std::endl;
    std::cout << std::endl;
}

// ChatGPT used to create FMSynth get sample formula
float FMSynth::getSample()
{
    float sample = 0.0f;

    // Loop through each carrier oscillator
    for (int i = 0; i < numOscillators; ++i) {
        float modulation = 0.0f;

        // Apply modulation from each modulator to the carrier
        for (int j = 0; j < numModulators; ++j) {
            modulation += modulatorBank[j]->getSample() * modulationIndices[j];
        }

        // Adjust carrier frequency by modulation
        float originalFreq = oscillatorBank[i]->getFreq();
        oscillatorBank[i]->setFreq(originalFreq + modulation);

        // Get the sample from the carrier
        sample += oscillatorBank[i]->getSample();

        // Reset the carrier frequency to its original value
        oscillatorBank[i]->setFreq(originalFreq);
    }
    return sample;
}
