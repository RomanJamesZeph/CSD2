#include <iostream>
#include "instrument.h"
#include "percussion.h"
#include "string.h"
#include "wind.h"


int main()
{
    String guitar("guitar", 33, 6);
    std::cout << "Name: " << guitar.getName() << std::endl;
    std::cout << "Pitch range: " << guitar.getPitchRange() << std::endl;
    std::cout << "String amount: " << guitar.getStringAmount() << std::endl;
    guitar.setSound("bing");
    guitar.play();

    Wind flute("flute", 37, true, false);
    std::cout << "Name: " << flute.getName() << std::endl;
    std::cout << "Pitch range: " << flute.getPitchRange() << std::endl;
    std::cout << "Woodwinds: " << flute.getWoodwinds() << std::endl;
    std::cout << "Brass: " << flute.getBrass() << std::endl;
    flute.setSound("ieie");
    flute.play();

    Percussion snare("snare", 0, false);
    std::cout << "Name: " << snare.getName() << std::endl;
    std::cout << "Pitch range: " << snare.getPitchRange() << std::endl;
    std::cout << "Melodic: " << snare.getMelodic() << std::endl;
    snare.setSound("bing");
    snare.play();

    return 0;
}