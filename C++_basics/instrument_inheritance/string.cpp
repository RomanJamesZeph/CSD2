#include <iostream>
#include "string.h"

String::String(std::string name, int pitchRange, int stringAmount) : Instrument(name, pitchRange)
{
    this->name = name;
    this->pitchRange = pitchRange;
    this->stringAmount = stringAmount;
}

int String::getStringAmount()
{
    return stringAmount;
}