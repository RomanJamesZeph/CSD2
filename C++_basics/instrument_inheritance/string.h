#include <iostream>
#include "instrument.h"

class String : public Instrument
{
    private:
        int stringAmount;

    public:
        String(std::string sound, int stringAmount);
        int getStringAmount();
};