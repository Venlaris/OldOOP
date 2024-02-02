#include "Point2D.h"
#include <iostream>

using namespace std;


Point2D::Point2D() : x(0), y(0) {} //default constructor

Point2D::Point2D(const Point2D& p) : x(p.x), y(p.y) {} //copy construcotr

Point2D::Point2D(float x1, float y1) : x(x1), y(y1) {} //parameterized constructor


float Point2D::disToPoints(const Point2D& p) const {
    float dis = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));

    return abs(dis);
}

string Point2D::toString() {
    string coords = to_string(x) + " , " + to_string(y);

    return coords;
}

Point2D Point2D::operator+(const Point2D& p) const {
    Point2D point;
    point.x = this->x + p.x;
    point.y = this->y + p.y;

    return point;
}
Point2D Point2D::operator=(const Point2D& p) {
    x = p.x;
    y = p.y;

    return *this;
}
bool Point2D::operator==(const Point2D& p) const {
    return (x == p.x && y == p.y);
}