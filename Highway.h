#pragma once

#include <vector>
#include <algorithm>
#include "Vehicle.h"

struct HighwayPatrol;

struct Highway
{
    void changeSpeed(int newSpeed);
    void addVehicle(Vehicle* v);
    void removeVehicle(Vehicle* v);
    int speedLimit = 65;

private:
    std::vector<Vehicle*> vehicles;
    void addVehicleInternal(Vehicle* v);
    void removeVehicleInternal(Vehicle* v);
    
};
