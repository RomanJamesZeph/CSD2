#include <iostream>
#include "instrument.h"


Instrument::Instrument(std::string sound)
{
    this->sound = sound;
}

void Instrument::setName(std::string name)
{
    this->name = name;
}

std::string Instrument::getName()
{
    return name;
}

void Instrument::setPitchRange(int pitchRange)
{
    this->pitchRange = pitchRange;
}

int Instrument::getPitchRange()
{
    return pitchRange;
}

void Instrument::play()
{
    std::cout << sound << std::endl;
}