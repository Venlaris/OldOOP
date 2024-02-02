#pragma once
#include <string>

using namespace std;

class Owner {
private:
    string name;
    string address;
    bool allowedToDrive;

public:
    Owner(const string& inName, const string& inAddress, bool drive);
    bool isAllowedToDrive() const;

    void print() const;
};