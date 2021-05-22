#include "Highway.h"
#include "Car.h"
#include "HighwayPatrol.h"
#include "Motorcycle.h"
#include "SemiTruck.h"


#include <cassert>

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
}

void Highway::addVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */
    if(Car* car = dynamic_cast<Car*>(v))
    {
        car->closeWindows();
    }
    else if(Motorcycle* chopper = dynamic_cast<Motorcycle*>(v))
    {
        chopper->setSpeed(105);
    }
    else if(SemiTruck* truck = dynamic_cast<SemiTruck*>(v))
    {
        truck->setSpeed(60);
    }
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */
    if(Car* car = dynamic_cast<Car*>(v))
    {
        car->tryToEvade();
    }
    else if(Motorcycle* chopper = dynamic_cast<Motorcycle*>(v))
    {
        chopper->tryToEvade();
    }
    else if(SemiTruck* truck = dynamic_cast<SemiTruck*>(v))
    {
        truck->pullOver();
    }
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
