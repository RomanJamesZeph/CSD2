#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "writeToFile.h"

int main()
{
    Sine sine(1, 1);
    std::cout << "Sine frequency: " << sine.getFreq() << "\n";
    std::cout << "Sine amplitude: " << sine.getAmp() << "\n";

    WriteToFile fileWriter("output.csv", true);
    for(int i = 0; i < SAMPLERATE; i++)
    {
        fileWriter.write(std::to_string(sine.getSample()) + "\n");
        sine.tick();
    }
    std::cout << "File created successfully.\n";
    return 0;
}