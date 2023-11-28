#include <iostream>
#include "oscillator.h"

int main()
{
    Oscillator osc(220, 0.5);
    osc.setFreq(255);
    std::cout << "Frequency: " << osc.getFreq() << std::endl;
    return 0;
}