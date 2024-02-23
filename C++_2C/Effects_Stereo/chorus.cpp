#include "chorus.h"
#include <iostream>

Chorus::Chorus()
{
    std::cout << "Chorus Constructor" << std::endl;
}

Chorus::~Chorus()
{
    std::cout << "Chorus Destructor" << std::endl;
    delete delay;
}

void Chorus::applyEffect(const float &input, float &output)
{

}

