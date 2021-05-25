#pragma once
#include "Vehicle.h"

struct SemiTruck : Vehicle
{
    SemiTruck(const std::string& name);
    ~SemiTruck() override;
    SemiTruck(const SemiTruck&);
    SemiTruck& operator=(const SemiTruck&);

    void honkHorn();
    void pullOver();
};
