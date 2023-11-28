#include <iostream>
#include "wind.h"

Wind::Wind(std::string name, int pitchRange, bool woodwinds, bool brass) : Instrument (name, pitchRange)
{
    this->name = name;
    this->pitchRange = pitchRange;
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