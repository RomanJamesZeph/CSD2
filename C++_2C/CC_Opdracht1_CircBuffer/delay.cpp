#include "delay.h"

Delay::Delay()
{
    std::cout << "Delay - constructor\n";
}

Delay::~Delay()
{
  std::cout << "Delay - destructor\n";
}

void Delay::setFeedback(float feedback)
{
    this->feedback=feedback;
}

float Delay::getFeedback()
{
    return feedback;
}