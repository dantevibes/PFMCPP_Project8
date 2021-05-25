#pragma once

#include <string>
#include <iostream>

struct HighwayPatrol;

struct Vehicle
{
    Vehicle(const std::string& n);
    
    virtual ~Vehicle() = default;
    Vehicle(const Vehicle&) = default;
    Vehicle& operator=(const Vehicle&) = default;
    
    virtual void setSpeed(int s);
    virtual void tryToEvade();

    friend HighwayPatrol;
protected:
    int speed = 0;
    std::string name;
};
