#pragma once
#include <string>

using namespace std;

class Body {
private:
    float width;
    float height;
    float length; //not in the description but lets make an actual car aight
    string colour;

public:
    Body(float inWidth, float inHeight, float inLength, const string& inColour);

    void print() const;
};