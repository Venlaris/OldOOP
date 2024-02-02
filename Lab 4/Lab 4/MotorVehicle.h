#pragma once
#include "Body.h"
#include "Engine.h"
#include "Owner.h"
#include <string>

using namespace std;



class MotorVehicle {
private:
    Engine* engine;
    Body* body;
    Owner* owner;

    float* wheelDiameter;
    int numberOfWheels;
    string model;

public:
    MotorVehicle(Engine* engi, Body* inBody, Owner* inOwner, float* diameter, int wheels, const string& inModel);

    ~MotorVehicle(); //Destructor to deallocate the wheelDiameter

    void print() const;
};