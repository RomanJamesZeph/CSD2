#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#pragma GCC diagnostic ignored "-Wc++11-extensions"

#define SAMPLERATE 44100

class Sine
{
    public:
        Sine(float frequency);
        ~Sine();

        float getSample();

        void tick();

        void setFrequency(float frequency);

        float getFrequency();

    private:
        float frequency;
        float phase = 0;
        float sample = 0;
};

#endif