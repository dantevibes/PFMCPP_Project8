#pragma once
#include "Vehicle.h"

struct SemiTruck : Vehicle
{
    SemiTruck(const std::string& name);
    ~SemiTruck() override = default;
    SemiTruck(const SemiTruck&) = default;
    SemiTruck& operator=(const SemiTruck&) = default;

    void setSpeed(int s) override;
    
    void pullOver();
};
