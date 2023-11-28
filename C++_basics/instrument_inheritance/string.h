#include <iostream>
#include "instrument.h"

class String : public Instrument
{
    private:
        int stringAmount;

    public:
        String(std::string name, int pitchRange, int stringAmount);
        int getStringAmount();
};