#include <iostream>
#include "instrument.h"

class Percussion : public Instrument
{
    private:
        bool melodic;

    public:
        Percussion(std::string sound, bool melodic);
        bool getMelodic();
};