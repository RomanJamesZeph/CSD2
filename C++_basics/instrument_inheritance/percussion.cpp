#include <iostream>
#include "percussion.h"

Percussion::Percussion(std::string name, int pitchRange, bool melodic) : Instrument(name, pitchRange)
{
    this->name = name;
    this->pitchRange = pitchRange;
    this->melodic = melodic;
}

bool Percussion::getMelodic()
{
    return melodic;
}