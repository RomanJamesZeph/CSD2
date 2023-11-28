#include <iostream>
#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_

class Instrument
{
    private:
        int pitchRange;
        std::string name;

    public:
        Instrument(std::string sound);
        std::string sound;
        void setName(std::string name);
        std::string getName();
        void setPitchRange(int pitchRange);
        int getPitchRange();
        void play();
};

#endif