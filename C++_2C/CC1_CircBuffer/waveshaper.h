#pragma once
#include "effect.h"

class Waveshaper : public Effect 
{
    public:
        Waveshaper();
        ~Waveshaper();
        void applyEffect(const float &input, float &output) override;
    private:
};