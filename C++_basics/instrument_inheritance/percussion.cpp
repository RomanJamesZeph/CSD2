#include <iostream>
#include "percussion.h"

Percussion::Percussion(std::string sound, bool melodic) : Instrument(sound)
{
    this->sound = sound;
    this->melodic = melodic;
}

bool Percussion::getMelodic()
{
    return melodic;
}