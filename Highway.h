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
    std::vector<Vehicle*> vehicles;
    int speedLimit = 65;

private:
    void addVehicleInternal(Vehicle* v);
    void removeVehicleInternal(Vehicle* v);
    
};
