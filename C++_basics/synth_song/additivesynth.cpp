#include "additivesynth.h"

AdditiveSynth::AdditiveSynth(std::string type, int numOscillators, float freq, float amp, float samplerate)
    : Synth(type, numOscillators, freq, amp, samplerate) 
{
    oscillatorBank = new Oscillator* [numOscillators];
    srand(time(0)); 
    if (type == "random")
    {
        for (int i = 0; i < numOscillators; ++i) {
            int random = rand() % 3;
            if (random == 0){
                oscillatorBank[i] = new Sine (freq = rand() %  20000 + 20, amp, samplerate);
                std::cout << "Freq " << i << ": " << freq << std::endl;
            }
            else if (random == 1){
                oscillatorBank[i] = new Sine (freq = rand() %  20000 + 20, amp, samplerate);
                std::cout << "Freq " << i << ": " << freq << std::endl;
            }
            else if (random == 2){
                oscillatorBank[i] = new Sine (freq = rand() %  20000 + 20, amp, samplerate);
                std::cout << "Freq " << i << ": " << freq << std::endl;
            }
        }
    }
    std::cout << "AdditiveSynth - constructor\n";
}

AdditiveSynth::~AdditiveSynth() 
{
    std::cout << "AdditiveSynth - deconstructor\n";
}