#include <iostream>

class Instrument
{
    public:
        std::string name;
        std::string sound;
        int pitchRange;

        void getName()
        {
            std::cout << name << std::endl;
        }
        void play()
        {
            std::cout << sound << std::endl;
        }
        void getPitchRange()
        {
            std::cout << pitchRange << std::endl;
        }
};

class String : public Instrument
{
    private:
        int amountOfStrings;
};

class Wind : public Instrument
{
    private:
        bool woodwinds;
        bool brass;

};

class Percussion : public Instrument
{
    private:
        bool melodic;
};

int main()
{
    String guitar;
    guitar.getName();
    guitar.play();
    guitar.getPitchRange();

    Wind flute;
    flute.getName();
    flute.play();
    flute.getPitchRange();

    Percussion snare;
    snare.getName();
    snare.play();
    snare.getPitchRange();
}