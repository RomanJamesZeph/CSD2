#include <iostream>
#include "instrument.h"

class Wind : public Instrument
{
    private:
        bool woodwinds;
        bool brass;

    public:
        Wind(std::string sound, bool woodwinds, bool brass);
        bool getWoodwinds();
        bool getBrass();
};