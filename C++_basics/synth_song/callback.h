#ifndef CALLBACK_H
#define CALLBACK_H

// chatGPT used to write comments

// Including dependencies
#include "jack_module.h"
#include "synth.h"
#include "oscillator.h"
#include "sine.h"
#include "triangle.h"
#include "square.h"
#include "melody.h"
#include "additivesynth.h"
#include "fmsynth.h"
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
    int numOscillators =  2;           // Number of oscillators to use.
    float amplitude = 0.5;             // Amplitude for the sound synthesis.
    int frameIndex = 0;                // Index to keep track of the current frame.
    double noteDelayFactor = 0.05;     // Factor to determine note delay.
    std::string waveFormOptions[3] = {"sine", "square", "triangle"}; // Waveform options.
    int numWaveFormOptions = 3;        // Number of waveform options available.
    UI console_ui;                     // User interface object for input handling.
    AdditiveSynth mySynth;             // Synthesizer object for sound generation.
    Melody melody;                     // Melody object to manage musical notes.
};

#endif //CALLBACK_H
