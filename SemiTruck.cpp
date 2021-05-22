#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}

void SemiTruck::setSpeed(int s)
{
    std::cout << "\nHighway is adjusting " << name << "'s speed to " << s << " mph" << std::endl;
    speed = s;
}

void SemiTruck::pullOver()
{
    std::cout << "Hey there officer, what can I do ya for?" << std::endl;
    setSpeed(0);
}
