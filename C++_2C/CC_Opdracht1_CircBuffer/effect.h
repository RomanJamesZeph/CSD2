#include <iostream>

class Effect
{
    public:
        Effect();
        ~Effect();
        void setDryWet(float dryWet);
        float getDryWet();

    private:
        float dryWet;
};