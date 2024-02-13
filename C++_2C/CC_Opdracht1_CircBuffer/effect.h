#include <iostream>

class Effect
{
    public:
        Effect(float dryWet = 1.0f);
        ~Effect();
        float processFrame(float input);
        void setDryWet(float dryWet);
        float getDryWet();

    protected:
        virtual float applyEffect(float input) = 0;

    private:
        float dry;
        float wet;
};