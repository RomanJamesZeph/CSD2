#include <iostream>
#include <thread>
#include <type_traits>
#include "math.h"
#include "oscillator.h"
#include "sine.h"
#include "square.h"
#include "triangle.h"
#include "audioToFile.h"
#include "callback.h"
#include "jack_module.h"

int main()
{
    Sine sine(1, 1, 44100);
    std::cout << "Sine frequency: " << sine.getFreq() << "\n";
    std::cout << "Sine amplitude: " << sine.getAmp() << "\n";

    WriteToFile fileWriter("output.csv", true);
    for(int i = 0; i < sine.getSamplerate(); i++)
    {
        fileWriter.write(std::to_string(sine.getSample()) + "\n");
        sine.tick();
    }
    std::cout << "File created successfully.\n";
    return 0;
}