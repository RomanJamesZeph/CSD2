#include <iostream>
#include "wind.h"

Wind::Wind(std::string sound, bool woodwinds, bool brass) : Instrument (sound)
{
    this->sound = sound;
    this->woodwinds = woodwinds;
    this->brass = brass;
}

bool Wind::getBrass()
{
    return brass;
}

bool Wind::getWoodwinds()
{
    return woodwinds;
}