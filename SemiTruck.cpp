#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}
SemiTruck::~SemiTruck() = default;
SemiTruck::SemiTruck(const SemiTruck&) = default;
SemiTruck& SemiTruck::operator=(const SemiTruck&) = default;

void SemiTruck::honkHorn()
{
    setSpeed(65);
    std::cout << "*HONK HOONK*  Let me on!" << std::endl;
}

void SemiTruck::pullOver()
{
    std::cout << "Hey there officer, what can I do ya for?" << std::endl;
    setSpeed(0);
}
