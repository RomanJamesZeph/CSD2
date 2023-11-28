#include <iostream>
#include "instrument.h"


Instrument::Instrument(std::string name, int pitchRange)
{
    this->name = name;
}

std::string Instrument::getName()
{
    return name;
}

int Instrument::getPitchRange()
{
    return pitchRange;
}

void Instrument::setSound(std::string sound)
{
    this->sound = sound;
}

void Instrument::play()
{
    std::cout << sound << std::endl;
}