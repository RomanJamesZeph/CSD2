#include <iostream>
#include "string.h"

String::String(std::string sound, int stringAmount) : Instrument(sound)
{
    this->sound = sound;
    this->stringAmount = stringAmount;
}

int String::getStringAmount()
{
    return stringAmount;
}