#include "Point2D.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

//the actual lab is further down but made this in case I needed it (this is easier to use just to use)
//also made this one way later than the og one
int main() {
	float x;
	float y;
	int numPoint;

	Point2D points[5];

	if (numPoint < 2 || numPoint > 5) {
		cout << "Only supports 2 to 5 points" << endl;
		return 1;
	}

	for (int i = 0; i < numPoint; ++i) {
		cout << "Enter the value for point " << i + 1 << ": ";
		cin >> x;
		cout << "Enter the value for point " << i + 1 << ": ";
		cin >> y;

		points[i] = Point2D(x, y);
	}

	for (int i = 0; i < numPoint; ++i) {
		for (int j = i + 1; j < numPoint; ++j) {
			float disPoint = points[i].disToPoints(points[j]);
			cout << "Distance between point " << i + 1 << "and point " << j + 1 << ": " << disPoint << endl;

			bool isPointEqual = points[i] == points[j];
			cout << "Is point " << i + 1 << " equal to point " << j + 1 << "? " << isPointEqual << endl;
		}
	}
	return 0;
}

							//actual lab
// 
// 
//void main() {
//	Point2D p1(54, 6123); //point 1
//	Point2D p2(145, 641); //point 2
//	Point2D p3(p1); //point 3, takes the values from p1
//	Point2D p4(p1+p3); //point 4, adds p1 and p3 together
//	Point2D p5 = p4; //point 5, is now equal to p4 which is p1 and p3 added together, p3 which is takes the values from p1
//
//	//you dont need all those bools nor do you actually need all the distPxPy
//	//if you already know which ones are equal and which ones aren't but if you don't then its nice to have
//
//	//all p1's
//	float distP1P2 = p1.disToPoints(p2);
//	float distP1P3 = p1.disToPoints(p3);
//	float distP1P4 = p1.disToPoints(p4);
//	float distP1P5 = p1.disToPoints(p5);
//
//	bool equalP1P2 = p1 == p2;
//	bool equalP1P3 = p1 == p3;
//	bool equalP1P4 = p1 == p4;
//	bool equalP1P5 = p1 == p5;
//
//	//all p2 except p1
//	float distP2P3 = p2.disToPoints(p3);
//	float distP2P4 = p2.disToPoints(p4);
//	float distP2P5 = p2.disToPoints(p5);
//
//	bool equalP2P3 = p2 == p3;
//	bool equalP2P4 = p2 == p4;
//	bool equalP2P5 = p2 == p5;
//
//	//all p3 except p1, p2
//	float distP3P4 = p3.disToPoints(p4);
//	float distP3P5 = p3.disToPoints(p5);
//
//	bool equalP3P4 = p3 == p4;
//	bool equalP3P5 = p3 == p5;
//
//	//all p4 except p1, p2, p3
//	float distP4P5 = p4.disToPoints(p5);
//
//	bool equalP4P5 = p4 == p5;
//
//	string pointString1 = p1.toString();
//	string pointString2 = p2.toString();
//	string pointString3 = p3.toString();
//	string pointString4 = p4.toString();
//	string pointString5 = p5.toString();
//
//	//this_thread::sleep_for(chrono::seconds(1)); is used to not just spew out all the cout messages at once
//	cout << "Point 1 values: " << pointString1 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Point 2 values: " << pointString2 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Point 3 values: " << pointString3 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Point 4 values: " << pointString4 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Point 5 values: " << pointString5 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//
//	//p1
//	cout << "\nDistance between P1 and P2: " << distP1P2 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Distance between P1 and P3: " << distP1P3 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Distance between P1 and P4: " << distP1P4 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Distance between P1 and P5: " << distP1P5 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//
//	//p2
//	cout << "\nDistance between P2 and P3: " << distP2P3 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Distance between P2 and P4: " << distP2P4 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Distance between P2 and P5: " << distP2P5 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//
//	//p3
//	cout << "\nDistance between P3 and P4: " << distP3P4 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Distance between P3 and P5: " << distP3P5 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//
//	//p4
//	cout << "\nDistance between P4 and P5: " << distP4P5 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//
//	cout << "\nIs p1 equal to p2? " << boolalpha << equalP1P2 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Is p1 equal to p3? " << boolalpha <<equalP1P3 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Is p1 equal to p4? " << boolalpha <<equalP1P4 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Is p1 equal to p5? " << boolalpha <<equalP1P5 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//
//	cout << "\nIs p2 equal to p3? " << boolalpha <<equalP2P3 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Is p2 equal to p4? " << boolalpha <<equalP2P4 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Is p2 equal to p5? " << boolalpha <<equalP2P5 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//
//	cout << "\nIs p3 equal to p3? " << boolalpha <<equalP3P4 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//	cout << "Is p3 equal to p4? " << boolalpha <<equalP3P5 << endl;
//	this_thread::sleep_for(chrono::seconds(1));
//
//	cout << "\nIs p4 equal to p5? " << boolalpha <<equalP4P5 << endl;
//}
