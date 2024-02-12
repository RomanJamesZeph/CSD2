#include <iostream>
#include <thread>
#include "math.h"
#include "writeToFile.h"
#define SAMPLERATE 44100

class FIR 
{
    public:
        FIR()
        {
            buffer = 0.f;
        }
        float process(float input)
        {
            output = 0.5f * input + 0.5f * buffer;
            buffer = input;
            return output;
        }
    private:
        float output;
        float buffer;
};

int main()
{
    FIR filter;
    float frequency = SAMPLERATE/2;

    // write 1 period of the waveform to a file and a buffer
    WriteToFile fileWriter("output.csv", true);

    for(int n = 0; n < SAMPLERATE; n++) {
        float sample = sin(2 * M_PI * frequency * n / SAMPLERATE);
        fileWriter.write(std::to_string(filter.process(sample)) + "\n");
  }
}