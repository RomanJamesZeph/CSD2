#include <iostream>
#include <string>

class Instrument{
    public:
        void play (std::string sound)
        {
            std::cout << sound << std::endl;
        }
};

int main (){
    Instrument myInstrument1;
    myInstrument1.play("Bazinga");
    
    Instrument myInstrument2;
    myInstrument2.play("Tjoooep");
}