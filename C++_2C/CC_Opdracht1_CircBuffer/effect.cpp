#include "effect.h"

Effect::Effect()
{
  std::cout << "Effect - constructor\n";
}

Effect::~Effect()
{
  std::cout << "Effect - deconstructor\n";
}

void Effect::setDryWet(float dryWet)
{
    this -> dryWet = dryWet;
}

float Effect::getDryWet()
{
    return dryWet;
}