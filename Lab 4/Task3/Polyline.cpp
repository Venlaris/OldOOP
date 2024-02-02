#include "Pointer2D.h"
#include "Polyline.h"
#include <iostream>

using namespace std;

Polyline::Polyline(int inPolylineSize) : polylineSize(inPolylineSize), polylineCurrSize(0) {
    polylineArray = new Point2D[polylineSize];
}


int Polyline::addPoint(Point2D& p) { //add's the point unless the list is already maxed
    if (polylineCurrSize < polylineSize) {

        polylineArray[polylineCurrSize] = p;
        polylineCurrSize++;
    }

    else {
        cout << "Oh! there's too many points in this line!" << endl;
    }
    return polylineCurrSize;
}


Point2D Polyline::getPoint(int i) { //finds the point
    if (i >= polylineCurrSize) {

        cout << "Out of bounds" << endl;
        return Point2D();
    }

    else {

        return polylineArray[i];
    }
}


void Polyline::removeLastPoint() { //removes the last point by reducing the list by one
    if (polylineCurrSize != 0)

        polylineCurrSize--; //dont need to traverse an array like you do with a list, simply reduce an array by 1! why? because arrays are static during run time

    else {
        cerr << "The polyline is empty" << endl;
    }
}


bool Polyline::hasPoint() { //checks if it has points

    if (polylineCurrSize == 0) {
        return false;
    }

    else {
        return true;
    }
}


int Polyline::inPolylineCurrSize() {
    return polylineCurrSize;
}


float Polyline::sumDistance() { //gets the sum distance between the points
    float distance = 0;
    for (int i = 0; i < polylineCurrSize - 1; i++) {
        distance += getPoint(i).disToPoints(getPoint(i + 1));
    }
    return distance;
}


void Polyline::coords() { //gets the coordinate and converts it to a string
    for (int i = 0; i < inPolylineCurrSize(); i++) {
        cout << getPoint(i).toString() << endl;
    }
}


Polyline::~Polyline() {
    delete[] polylineArray;
}