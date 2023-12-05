#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "oscillator.h"
#include "sine.h"
#include "square.h"
#include "triangle.h"
#include "writeToFile.h"

int main()
{
    Sine sine(100, 1);
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

    // Square square(1, 1);
    // std::cout << "Square frequency: " << square.getFreq() << "\n";
    // std::cout << "Square amplitude: " << square.getAmp() << "\n";

    // WriteToFile fileWriter("output.csv", true);
    // for(int i = 0; i < SAMPLERATE; i++)
    // {
    //     fileWriter.write(std::to_string(square.getSample()) + "\n");
    //     square.tick();
    // }
    // std::cout << "File created successfully.\n";
    // return 0;

    // Triangle triangle(100, 1);
    // std::cout << "Triangle frequency: " << triangle.getFreq() << "\n";
    // std::cout << "Triangle amplitude: " << triangle.getAmp() << "\n";

    // WriteToFile fileWriter("output.csv", true);
    // for(int i = 0; i < SAMPLERATE; i++)
    // {
    //     fileWriter.write(std::to_string(triangle.getSample()) + "\n");
    //     triangle.tick();
    // }
    // std::cout << "File created successfully.\n";
    // return 0;
}