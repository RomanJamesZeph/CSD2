#pragma once

#include <iostream>
#include "effect.h"

#define BUFFER_SIZE 512

class Waveshaper : public Effect 
{
    public:
        Waveshaper(float saturation = 4, float dryWet = 1.0f);
        ~Waveshaper();
        void applyEffect(const float &input, float &output) override;
        void setSaturation(float saturation);
        
    private:
        float saturation;
        float buffer[BUFFER_SIZE];
};