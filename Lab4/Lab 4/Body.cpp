#include "Body.h"
#include <iostream>

using namespace std;

Body::Body(float inWidth, float inHeight, float inLength, const string& inColour) : width(inWidth), height(inHeight), length(inLength), colour(inColour) {

}

void Body::print() const {
    cout << "The width is: " << width << " meters" << endl;
    cout << "The length is: " << length << " meters" << endl;
    cout << "The height is: " << height << " meters" << endl;
    cout << "The colour is: " << colour << endl;
}