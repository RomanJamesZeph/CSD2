#ifndef _ADDITIVESYNTH_H_
#define _ADDITIVESYNTH_H_
#include "synth.h"

class AdditiveSynth : public Synth 
{
    public:
        // constructor and deconstructor
        AdditiveSynth(int numPartials);
        ~AdditiveSynth();
        float getSample();
        
    private:
        
};

#endif
