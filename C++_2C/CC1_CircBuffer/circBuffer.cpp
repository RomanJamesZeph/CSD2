#include "circBuffer.h"


CircBuffer::CircBuffer(int numSamplesDelay)
{
  std::cout << "CircBuffer - constructor\n";
  readHeader = 0;
  writeHeader = 0;
}

CircBuffer::~CircBuffer()
{
    std::cout << "CircBuffer - deconstructor\n";
  // TODO - release the dynamic allocated array
}

void CircBuffer::write(float sample)
{
  buffer[writeHeader] = sample;
  writeHeader = (writeHeader + 1) % bufferSize;
}

float CircBuffer::read()
{
  float sample = buffer[readHeader];
  readHeader = (readHeader + 1) % bufferSize;
  return sample;
}

void CircBuffer::setDistanceRW()
{

}