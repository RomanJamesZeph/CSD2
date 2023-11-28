#include <iostream>
#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_

class Instrument
{
    private:
        std::string sound;
    
    protected:
        int pitchRange;
        std::string name;

    public:
        Instrument(std::string name, int pitchRange);
        std::string getName();
        int getPitchRange();
        void setSound(std::string sound);
        void play();
};

#endif