#include "delay.h"

Delay::Delay(int delaySamples, int maxDelaySamples, 
        float feedback, float dryWet) : Effect(dryWet), writeH(0), readH(0)
{
    std::cout << "Delay - constructor\n";
}

Delay::~Delay()
{
  std::cout << "Delay - destructor\n";
}

void Delay::prepare(float samplerate)
{

}

float Delay::applyEffect(float sample)
{
    return sample;
}

void Delay::setFeedback(float feedback)
{
    if (feedback > 0.0f && feedback < 0.99f)
    {
        this->feedback=feedback;
    }
    else
    {
        std::cout << "Error - wrong feedback value\n";
    }
}

float Delay::getFeedback()
{
    return feedback;
}