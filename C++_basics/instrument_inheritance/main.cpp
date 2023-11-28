#include <iostream>
#include "instrument.h"
#include "percussion.h"
#include "string.h"
#include "wind.h"


int main()
{
    String guitar("bing", 6);
    guitar.setName("guitar");
    std::cout << "Name: " << guitar.getName() << std::endl;
    guitar.setPitchRange(33);
    std::cout << "Pitch range: " << guitar.getPitchRange() << std::endl;
    std::cout << "String amount: " << guitar.getStringAmount() << std::endl;
    guitar.play();

    Wind flute("iieiee", true, false);
    flute.setName("flute");
    std::cout << "Name: " << flute.getName() << std::endl;
    flute.setPitchRange(37);
    std::cout << "Pitch range: " << flute.getPitchRange() << std::endl;
    std::cout << "Woodwinds: " << flute.getWoodwinds() << std::endl;
    std::cout << "Brass: " << flute.getBrass() << std::endl;
    flute.play();

    Percussion snare("donk", false);
    snare.setName("snare");
    std::cout << "Name: " << snare.getName() << std::endl;
    snare.setPitchRange(0);
    std::cout << "Pitch range: " << snare.getPitchRange() << std::endl;
    std::cout << "Melodic: " << snare.getMelodic() << std::endl;
    snare.play();

    return 0;
}