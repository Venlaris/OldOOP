#include "Owner.h"
#include <iostream>

using namespace std;

Owner::Owner(const string& inName, const string& inAddress, bool drive) : name(inName), address(inAddress), allowedToDrive(drive) {}

bool Owner::isAllowedToDrive() const {
    return allowedToDrive;
}

void Owner::print() const {
    cout << "Your name is: " << name << endl;
    cout << "Your address is: " << address << endl;

    if (allowedToDrive) {
        cout << "You are allowed to drive! " << allowedToDrive << endl;
    }
    else if (!allowedToDrive) {
        cout << "You are not allowed to drive. " << allowedToDrive << endl;
    }
}