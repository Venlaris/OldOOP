#include "Engine.h"
#include <iostream>

using namespace std;

Engine::Engine(float litres, int cylinders) : sizeInLitres(litres), numberOfCylinders(cylinders) {

}

void Engine::print() const {
    cout << "The size of the engine is: " << sizeInLitres << " liters" << endl;
    cout << "The number of cylinders is: " << numberOfCylinders << endl;
}