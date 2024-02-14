#include <iostream>

class Effect
{
    public:
        Effect(float dryWet = 1.0);
        virtual ~Effect();
        virtual void prepare(float rate) {};


        float processFrame(float input);

        // setters & getters
        void setDryWet(float dryWet);

    protected:
        // abstract method
        virtual float applyEffect(float input) = 0;
    private:
        float dry;
        float wet;
};