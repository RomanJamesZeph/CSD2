#include <iostream>
#include "effect.h"

class Delay : public Effect
{
    public:
        Delay();
        ~Delay();
        void setFeedback(float feedback);
        float getFeedback();
    
    private:
        float feedback;
};