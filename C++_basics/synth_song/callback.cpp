#include "callback.h"

// chatGPT used to write comments

// Constructor of CustomCallback class.
// Initializes the Synth object and adds oscillators based on user input.
CustomCallback::CustomCallback() : mySynth(numOscillators)
{
  // Loop through each oscillator to configure it.
  for (int i = 0; i < numOscillators; ++i) {
    // Retrieve user selection for wave type.
    int waveTypeSelection = console_ui.retrieveUserSelection(waveFormOptions, numWaveFormOptions);
    std::string waveType = waveFormOptions[waveTypeSelection];

    // Retrieve frequency within a specified range from the user.
    float freq = console_ui.retrieveValueInRange("frequency", 20, 20499);

    // Add oscillator with specified type, frequency, amplitude, and sample rate.
    mySynth.addOscillator(i, waveType, freq, amplitude, samplerate);
  }

  // Log constructor call.
  std::cout << "CustomCallback - constructor\n";
}

// Destructor of CustomCallback class.
// Responsible for cleanup (if needed).
CustomCallback::~CustomCallback()
{
  // Log destructor call.
  std::cout << "CustomCallback - deconstructor\n";
}

// Converts MIDI pitch to frequency.
double CustomCallback::mtof(float mPitch)
{
  // Formula to convert MIDI note number to frequency.
  return 440.0 * pow(2.0, (mPitch - 69.0f) / 12.0f);
}

// Updates the pitch of the Synth based on the current note in the melody.
void CustomCallback::updatePitch(Melody& melody, Synth& mySynth) {
  // Get the current note from the melody.
  float note = melody.getNote();

  // Convert the note to frequency.
  double freq = mtof(note);

  // Log the note and its frequency.
  std::cout << "next note: " << note << ", has frequency " << freq << std::endl;

  // Set the frequency of the synthesizer.
  mySynth.setFreq(freq);
}

// Prepares the callback with the given sample rate.
void CustomCallback::prepare(int rate) 
{
  // Update the pitch based on the current melody and synthesizer state.
  updatePitch(melody, mySynth);

  // Set the sample rate.
  samplerate = static_cast<float>(rate);

  // Log the set sample rate.
  std::cout << "\nsamplerate: " << samplerate << "\n";
}

// Processes the audio buffer.
void CustomCallback::process(AudioBuffer buffer) {
  // Unpack the buffer structure for easier use.
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

  // Process each output channel.
  for (int channel = 0; channel < numOutputChannels; ++channel) {
    // Process each sample in the frame.
    for (int sample = 0; sample < numFrames; ++sample) {
      // Set the sample value in the output channel.
      outputChannels[channel][sample] = mySynth.getSample() * amplitude;
      
      // Advance the state of the synthesizer.
      mySynth.tick();

      // Check if it's time to update the pitch.
      if(frameIndex >= noteDelayFactor * samplerate) 
      {
        // Reset the frame index and update the pitch.
        frameIndex = 0;
        updatePitch(melody, mySynth);
      }
      else 
      {
        // Increment the frame index.
        frameIndex++;
      }
    } // End of sample loop.
  } // End of channel loop.
} // End of process function.