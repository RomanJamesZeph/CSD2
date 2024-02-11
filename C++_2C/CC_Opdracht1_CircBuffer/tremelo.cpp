#include "tremelo.h"

Tremelo::Tremelo()
{
  std::cout << "Tremelo - constructor\n";
}

Tremelo::~Tremelo()
{
  std::cout << "Tremelo - deconstructor\n";
}

void Tremelo::setPhase(float phase)
{
    this->phase = phase;
}

float Tremelo::getPhase()
{
    return phase;
}

void Tremelo::setShape(char shape)
{
    this->shape = shape;
}

char Tremelo::getShape()
{
    return shape;
}