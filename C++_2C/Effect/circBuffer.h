#pragma once
#define bufferSize 20

#include <iostream>


class CircBuffer 
{
  public:
    CircBuffer(int numSamplesDelay);
    ~CircBuffer();

    void write(float sample);
    float read();
    void setDistanceRW();

  private:
    float buffer[bufferSize];
    int readHeader;
    int writeHeader;
};
