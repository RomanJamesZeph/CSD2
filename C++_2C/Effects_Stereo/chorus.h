#pragma once
#include "effect.h"
#include "delay.h"

class Chorus : public Effect
{
    public:
        Chorus();
        ~Chorus();
        void applyEffect(const float &input, float &output) override;
    private:
        Delay *delay;
};