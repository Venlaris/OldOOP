#include "MotorVehicle.h"
#include <iostream>

using namespace std;

MotorVehicle::MotorVehicle(Engine* engi, Body* inBody, Owner* inOwner, float* diameter, int wheels, const string& inModel) : engine(engi), body(inBody), owner(inOwner), wheelDiameter(diameter), numberOfWheels(wheels), model(inModel) {

    wheelDiameter = new float[numberOfWheels];

    for (int i = 0; i < numberOfWheels; ++i) {
        wheelDiameter[i] = diameter[i];
    }
}

MotorVehicle::~MotorVehicle() {
    //Deallocate memory
    delete[] wheelDiameter;
}

void MotorVehicle::print() const {
    cout << "\nPrinting your car info:" << endl;
    cout << "Amount of wheels: " << numberOfWheels << endl;

    for (int i = 0; i < numberOfWheels; ++i) { //to list out each wheeldieameter
        cout << "Diameter for wheel " << i + 1 << ": " << wheelDiameter[i] << " diameters" << endl;
    }

    cout << "The model is: " << model << endl;

    engine->print();
    body->print();
    owner->print();
}