#include <iostream>

class Instrument
{
    private:
        std::string name;
        std::string sound;
        int pitchRange;

    public:
        void setName(std::string name)
        {
            this->name = name;
        }

        std::string getName()
        {
            std::cout << "Instrument name: " << name << std::endl;
            return name;
        }

        void setPitchRange(int pitchRange)
        {
            this->pitchRange = pitchRange;
        }

        int getPitchRange()
        {
            std::cout << "Pitchrange: " << pitchRange << std::endl;
            return pitchRange;
        }

        void play()
        {
            std::cout << sound << std::endl;
        }
};

class String : public Instrument
{
    private:
        int stringAmount;

    public:
        void setStringAmount(int stringAmount)
        {
            this->stringAmount = stringAmount;
        }
        int getStringAmount()
        {
            std::cout << "StringAmount: " << stringAmount << std::endl;
            return stringAmount;
        }
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
    guitar.setName("guitar");
    guitar.getName();
    guitar.setPitchRange(33);
    guitar.getPitchRange();
    guitar.setStringAmount(6);
    guitar.getStringAmount();
    guitar.play();

    Wind flute;
    flute.setName("flute");
    flute.getName();
    flute.setPitchRange(37);
    flute.getPitchRange();
    flute.play();

    Percussion snare;
    snare.setName("snare");
    snare.getName();
    snare.play();
    snare.setPitchRange(0);
    snare.getPitchRange();
}