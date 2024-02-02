#pragma once
#include "Pointer2D.h"

class Polyline {
private:

    Point2D* polylineArray;

    int polylineSize;
    int polylineCurrSize;

public:

    int addPoint(Point2D& p);

    Point2D getPoint(int i);

    void removeLastPoint(); //only last point

    bool hasPoint();

    int inPolylineCurrSize();

    float sumDistance();

    void coords();

    Polyline(int inPolylineSize);
    virtual ~Polyline();
};
