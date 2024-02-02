#pragma once
#include <math.h>
#include <string>

using namespace std;

class Point2D {
private:
    float x;
    float y;

public:
    Point2D(); //default constructor
    Point2D(const Point2D& p); //copy constructor
    Point2D(float x1, float y2); //parameterized constructor 

    Point2D operator+(const Point2D& p) const; //+ overload
    Point2D operator=(const Point2D& p); //= overload
    bool operator==(const Point2D& p) const; //== overload

    float disToPoints(const Point2D& p) const;

    std::string toString();
};