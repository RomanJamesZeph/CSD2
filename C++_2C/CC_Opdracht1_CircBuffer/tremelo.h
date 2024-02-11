#include <iostream>
#include "effect.h"

class Tremelo : public Effect
{
    public:
        Tremelo();
        ~Tremelo();
        void setPhase(float phase);
        float getPhase();
        void setShape(char shape);
        char getShape();

    private:
        float phase;
        char shape;
}