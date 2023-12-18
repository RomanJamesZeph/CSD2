#ifndef CALLBACK_H
#define CALLBACK_H

enum SynthType {
    FM_SYNTH,
    ADDITIVE_SYNTH
};


// chatGPT used to write comments and chosen synth type functionality

// Including dependencies
#include "jack_module.h"
#include "synth.h"
#include "fmsynth.h"
#include "additivesynth.h"
#include "melody.h"
#include "ui.h"

// CustomCallback class definition
// This class is designed to handle audio callback functionality.
class CustomCallback : public AudioCallback {
public:
    // Constructor: Initializes the CustomCallback object.
    CustomCallback();

    // Destructor: Handles cleanup tasks when a CustomCallback object is destroyed.
    ~CustomCallback();
    
    // Converts MIDI pitch value to frequency (in Hz).
    double mtof(float mPitch);

    // Updates the pitch of a synthesizer based on the current melody.
    void updatePitch(Melody& melody, Synth& mySynth);

    // Prepares the callback for audio processing, setting the sample rate.
    void prepare(int rate) override;

    // Processes the audio buffer for each callback invocation.
    void process(AudioBuffer buffer) override;

private:
    // Member variables
    float samplerate = 44100;          // Default sample rate.           
    int numCarriers;               // Number of carriers to use.
    int numModulators;             // Number of modulators to use.
    float amplitude = 1;             // Amplitude for the sound synthesis.
    int frameIndex = 0;                // Index to keep track of the current frame.
    double noteDelayFactor = 0.5;     // Factor to determine note delay.
    std::string waveFormOptions[3] = {"sine", "square", "triangle"}; // Waveform options.
    int numWaveFormOptions = 3;        // Number of waveform options available.
    std::string synthTypeOptions[2] = {"fm", "additive"};
    int numSynthTypeOptions = 2;
    UI console_ui;                     // User interface object for input handling.
    SynthType chosenSynthType;
    FMSynth myFMSynth;
    AdditiveSynth myAdditiveSynth;
    Melody melody;                     // Melody object to manage musical notes.
};

#endif //CALLBACK_H
