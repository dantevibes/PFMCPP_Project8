#pragma once
#include "Vehicle.h"

struct SemiTruck : Vehicle
{
    SemiTruck(const std::string& name);
    ~SemiTruck();

    void pullOver();
};
