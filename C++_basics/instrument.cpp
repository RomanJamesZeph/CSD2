#include <iostream>
#include <string>

// class Instrument{
//     public:
//         Instrument(std::string sound){
//             std::cout << sound << std::endl;
//         }
// };

// int main (){
//     Instrument myInstrument1("Bazinga");
    
//     Instrument myInstrument2("Tjoooep");
// }

class Instrument{
    public:
        std::string sound;
        void play(){
            std::cout << sound << std::endl;
        }
};

int main (){
    Instrument myInstrument1;
    myInstrument1.sound = ("Bazinga");
    myInstrument1.play();

    
    Instrument myInstrument2;
    myInstrument2.sound = ("Tjoooep");
    myInstrument2.play();
}