#include "Highway.h"
#include "Car.h"
#include "HighwayPatrol.h"
#include "Motorcycle.h"
#include "SemiTruck.h"


#include <cassert>

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    Highway* thisHW = this;
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */
    if(Car* car = dynamic_cast<Car*>(v))
    {
        car->closeWindows();
    }
    else if(HighwayPatrol* hwPatrol = dynamic_cast<HighwayPatrol*>(v))
    {
        hwPatrol->scanHighway(thisHW);
    }
    else if(Motorcycle* cyclist = dynamic_cast<Motorcycle*>(v))
    {
        cyclist->setSpeed(80);
    }
    else if(SemiTruck* truck = dynamic_cast<SemiTruck*>(v))
    {
        
    }
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    Highway* thisHW = this;
    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */
    if(Car* vehic = dynamic_cast<Car*>(v))
    {
        vehic->tryToEvade();
    }
    else if(HighwayPatrol* hwPatrol = dynamic_cast<HighwayPatrol*>(v))
    {
        //hwPatrol->pullOver();
    }
    else if(Motorcycle* vehic = dynamic_cast<Motorcycle*>(v))
    {
        vehic->tryToEvade();
    }
    else if(SemiTruck* vehic = dynamic_cast<SemiTruck*>(v))
    {
        
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
