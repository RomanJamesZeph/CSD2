#include "callback.h"

// chatGPT used to write comments and chosen synth type functionality

// Constructor of CustomCallback class.
// Initializes the Synth object and adds oscillators based on user input.
CustomCallback::CustomCallback() : myFMSynth(1, 0), myAdditiveSynth(1)
{
    // Ask user for synth type
    int synthTypeSelection = console_ui.retrieveUserSelection(synthTypeOptions, numSynthTypeOptions);
    chosenSynthType = static_cast<SynthType>(synthTypeSelection);
    if (chosenSynthType == FM_SYNTH) 
    {
        numCarriers = console_ui.retrieveValueInRange("Number of carriers", 1, 10);
        numModulators = console_ui.retrieveValueInRange("Number of modulators", 0, 10);
        // Initialize carriers
        for (int i = 0; i < numCarriers; ++i) 
        {
            std::cout << "carrier " << i + 1<< ":\n";
            // Retrieve user selection for carrier wave type.
            int waveTypeSelection = console_ui.retrieveUserSelection(waveFormOptions, numWaveFormOptions);
            std::string waveType = waveFormOptions[waveTypeSelection];

            // Retrieve carrier frequency within a specified range from the user.
            float freq = console_ui.retrieveValueInRange("frequency", 20, 20499);   

            // Add carrier with specified type, frequency, amplitude, and samplerate.
            myFMSynth.addOscillator(i, waveType, freq, amplitude / numCarriers, samplerate); 
        }
        // Initialize modulators
        for (int i = 0; i < numModulators; ++i) 
        {
            std::cout << "modulator " << i + 1 << ":\n";
            // Retrieve user selection for modulator wave type.
            int waveTypeSelection = console_ui.retrieveUserSelection(waveFormOptions, numWaveFormOptions);
            std::string modWaveType = waveFormOptions[waveTypeSelection];

            // Retrieve modulation frequency within a specified range from the user.
            float modFreq = console_ui.retrieveValueInRange("modulation frequency", 20, 20499);

            // Retrieve modulation frequency within a specified range from the user.
            float modIndex = console_ui.retrieveValueInRange("modulation index", 0.1, 10);

            // Add modulator with specified type, frequency, amplitute, index and samplerate
            myFMSynth.addModulator(i, modWaveType, modFreq, amplitude / numModulators, modIndex, samplerate);
        }

    } 
    else if (chosenSynthType == ADDITIVE_SYNTH) 
    {
        // Ask for number of partials
        int numPartials = console_ui.retrieveValueInRange("Number of partials", 1, 10);
        for (int i = 0; i < numPartials; ++i) 
        {
            std::cout << "partial " << i + 1 << ":\n";
            // Retrieve user selection for partial wave type.
            int waveTypeSelection = console_ui.retrieveUserSelection(waveFormOptions, numWaveFormOptions);
            std::string waveType = waveFormOptions[waveTypeSelection];

            // Retrieve partial frequency within a specified range from the user.
            float freq = console_ui.retrieveValueInRange("frequency", 20, 20499);   

            // Add partial with specified type, frequency, amplitude, and samplerate.
            myAdditiveSynth.addOscillator(i, waveType, freq, amplitude / numPartials, samplerate); 
        }
    }

    // std::cout << "CustomCallback - constructor\n";
}

// Destructor of CustomCallback class.
CustomCallback::~CustomCallback()
{
    // std::cout << "CustomCallback - deconstructor\n";
}

// Converts MIDI pitch to frequency.
double CustomCallback::mtof(float mPitch)
{
  // Formula to convert MIDI note number to frequency.
  return 440.0 * pow(2.0, (mPitch - 69.0f) / 12.0f);
}

// Updates the pitch of the Synth based on the current note in the melody.
void CustomCallback::updatePitch(Melody& melody, Synth& mySynth) 
{
    // Get the current note from the melody.
    float note = melody.getNote();

    // Convert the note to frequency.
    double freq = mtof(note);

    // Log the note and its frequency.
    std::cout << "next note: " << note << ", has frequency " << freq << std::endl;

    if (chosenSynthType == FM_SYNTH) {
        myFMSynth.setFreq(freq);
    } else if (chosenSynthType == ADDITIVE_SYNTH) {
        myAdditiveSynth.setFreq(freq);
    }
}

// Prepares the callback with the given sample rate.
void CustomCallback::prepare(int rate) 
{
    // Set the sample rate.
    samplerate = static_cast<float>(rate);

    // Log the set sample rate.
    std::cout << "\nsamplerate: " << samplerate << "\n";
}


void CustomCallback::process(AudioBuffer buffer) {
    for (int i = 0; i < buffer.numFrames; ++i) {
        if (chosenSynthType == FM_SYNTH) {
            buffer.outputChannels[0][i] = myFMSynth.getSample();
            myFMSynth.tick();
        } else if (chosenSynthType == ADDITIVE_SYNTH) {
            buffer.outputChannels[0][i] = myAdditiveSynth.getSample();
            myAdditiveSynth.tick();
        }
        if(frameIndex >= noteDelayFactor * samplerate) {
            // Reset the frame index and update the pitch based on the synth type.
            if (chosenSynthType == FM_SYNTH) {
                updatePitch(melody, myFMSynth);
            } else if (chosenSynthType == ADDITIVE_SYNTH) {
                updatePitch(melody, myAdditiveSynth);
            }
            frameIndex = 0;
        }
        else {
            // Increment the frame index.
            frameIndex++;
        }
    }
}