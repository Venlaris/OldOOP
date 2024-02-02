#pragma once

class Engine {
private:
    float sizeInLitres;
    int numberOfCylinders;

public:
    Engine(float litres, int cylinders);

    void print() const;
};