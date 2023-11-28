#include <iostream>
#include "instrument.h"

class Percussion : public Instrument
{
    private:
        bool melodic;

    public:
        Percussion(std::string name, int pitchRange, bool melodic);
        bool getMelodic();
};