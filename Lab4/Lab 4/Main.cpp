#include "Body.h"
#include "Engine.h"
#include "Owner.h"
#include "MotorVehicle.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	char answer;

	string signUp; //realised too late that char just takes the first letter no matter what the user types, elected to just have a new variable for the "newsletter signup" instead of having to go back through the entire code
	string inModel;
	string inColour;
	string inName;
	string inAddress;

	float engineSize, wheelDiameters[4];
	float inWidth, inHeight, inLength;
	int cylinders, numberOfWheels;
	int attempts = 0;
	int count = 0;

	bool allowedToDrive = false;
	bool hasDigit;


	cout << "Hi welcome to 'create your own vehicle'!" << endl;
	cout << "To start of we're going to get a sense of what type of vehicle it is so please, put in the amount of wheels the vehicle uses:";
	while (true) {
		cin >> numberOfWheels;
		if (cin.good()) { //to make sure the uses a number
			break;
		}

		else if (cin.fail()) { //if they use something that isn't a letter
			attempts++;
			if (attempts == 3) {
				cout << "\nCongrats you failed!";
				return 0;
			}

			cout << "Use a number instead: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
	}
	float* tireDiameters = new float(numberOfWheels);

	//for (int i = 0; i < numberOfWheels; ++i) { //Dynamically allocated array for the wheelDiameters
	//	if (numberOfWheels >= 8) {
	//		cout << "nah thats too many";
	//		return 0;
	//	}
	//	cout << "Enter the wheel dimension for wheel " << i + 1 << ":" << endl;
	//	cin >> wheelDiameters[i];

	//}

	if (numberOfWheels == 2) {
		cout << "Aha a motorcycle huh interesting.. well let's get started with wheel dimensions" << endl;

		for (int i = 0; i < numberOfWheels; ++i) { //Dynamically allocated array for the wheelDiameters
			cout << "\nEnter the wheel dimension for wheel " << i + 1 << ": "; //Decided to use this loop here instead of the start
			cin >> wheelDiameters[i]; //It may be less dynamically allocated but makes for a better user experience, it is moved down to the "else" case as well for the x amount of wheels the user chooses not sure why, looks better
		}


		//Engine size
		while (true) {
			cout << "Now enter the size of the engine in litres: " << endl;
			cin >> engineSize;

			if (engineSize > 8) {
				cout << "Damn you have the biggest engine in the world, are you sure you put in the right value? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Alright then we'll move on to cylinders" << endl;
					break;
				}

				else if (answer == 'n') {
					cout << "Alright provide your new answer" << endl;
					cin >> engineSize;
				}

				else {
					cout << "Not an actual answer try again" << endl;
				}
			}
			break;
		}
		cin.clear();


		//Amount of cylinders
		while (true) {
			cout << "Secondly how many cylinders should it have?" << endl;
			cin >> cylinders;

			if (cylinders > 8) {
				cout << "That's a lot of cylinders are you sure about this? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Alright moving on to the next section" << endl;
					break;
				}

				else if (answer == 'n') {
					cout << "Alright provide your new answer" << endl;
					cin >> cylinders;
				}

				else {
					cout << "Not an actual answer try again" << endl;
					cin.clear();
				}
			}
			break;
		}
		cin.clear();


		//Body width
		while (true) {
			cout << "Okay now we're going to need the width in meters" << endl;
			cin >> inWidth;

			if (inWidth > 2) {
				cout << "That's a pretty wide motorcycle huh, but I respect it, but still, do you want to change it? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Want would you like to change the width to?" << endl;
					cin >> inWidth;
					break;
				}

				else if (answer == 'n') {
					cout << "Alright perfect, moving on to length" << endl;
					break;
				}

				else {
					cout << "Not an actual answer try again" << endl;
					cin.clear();
				}
			}
			break;
		}
		cin.clear();


		//Body length
		while (true) {
			cout << "Now we're going to need the length in meters" << endl;
			cin >> inLength;

			if (inLength > 3) {
				cout << "Alright that's a pretty long motorcycle, a limousine motorcycle? Do you want to change it? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "What do you want to change it to?" << endl;
					cin >> inLength;
				}

				else if (answer == 'n') {
					cout << "Aight perfect, moving on to height" << endl;
					break;
				}

				else {
					cout << "Not a valid answer, try again" << endl;
					cin.clear();
				}
			}
			break;
		}
		cin.clear();


		//Body height
		while (true) {
			cout << "Now how tall should it be?" << endl;
			cin >> inHeight;

			if (inHeight > 2) {
				cout << "Now thats a tall motorcycle! Cool, but still, would you like to change it? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Alright what would you like to change it to?" << endl;
					cin >> inHeight;
				}

				else if (answer == 'n') {
					cout << "Alright lets move on to the colour" << endl;
					break;
				}

				else {
					cout << "Not a valid answer, try again" << endl;
					cin.clear();
				}
			}
			break;
		}
		cin.clear();


		//Body colour
		attempts = 0;
		cout << "What colour do you want the motorcycle to be?" << endl;

		while (true) {
			cin >> inColour;
			bool hasDigit = false;

			for (int i = 0; i < inColour.length(); i++) { //this monstrosity is used to deal with cases where the user puts in a number
				for (char c : inColour) {
					if (isdigit(c)) {
						hasDigit = true;
						break;
					}
				}

				if (!hasDigit) {
					cout << "Happy with the colour? Y/N" << endl;
					cin >> answer;
					answer = tolower(answer);

					if (answer == 'y') {
						cout << "Alright lets move on to the model" << endl;
						break;
					}

					else if (answer == 'n') { //yes if you put in a number here the colour could still be a number, could be solved by just using the same for loop used earlier
						cout << "What would you like to change it to?" << endl; //this is also a problem for the body model
						cin >> inColour;
					}

					else {
						cout << "Not a valid answer, try again" << endl;
						cin.clear();
					}

				}

				else if (hasDigit) {
					attempts++;
					if (attempts == 3) {
						cout << "Aight no colour no car." << endl;
						return -1;
					}

					cout << "\nJust say a colour man: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;  //could also put the check here (or having a 2nd check) and force you to do the this question until it passes before it breaks out until the next question
		}
		cin.clear();


		//Body model
		attempts = 0;
		cout << "What model do you want the motorcycle to be?" << endl;

		while (true) {
			cin >> inModel;
			for (int i = 0; i < inModel.length(); i++) {
				bool hasDigit = false;
				for (char c : inModel) {
					if (isdigit(c)) {
						hasDigit = true;
						break;
					}
				}
				cout << "Happy with the model? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Alright lets move on to the last part" << endl;
					break;
				}

				else if (answer == 'n') {
					cout << "What would you like to change it to?" << endl;
					cin >> inModel;
					break;
				}

				else {
					cout << "Not a valid answer, try again" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;
		}
	}


	//
	//
	//
	//
	//
	//
	// 
	// NEXT VEHICLE STARTS HERE
	// 
	//
	//
	//
	//
	//
	//


	else if (numberOfWheels == 4) {
		cout << "Alright a normal car... perfect" << endl;


		for (int i = 0; i < numberOfWheels; ++i) { //Dynamically allocated array for the wheelDiameters
			cout << "\nEnter the wheel dimension for wheel " << i + 1 << ": "; //Decided to use this loop here instead of the start
			cin >> wheelDiameters[i]; //It may be less dynamically allocated but makes for a better user experience, it is moved down to the "else" case as well for the x amount of wheels the user chooses not sure why, looks better
		}


		//Engine size
		while (true) {
			cout << "First enter the size of the engine in litres" << endl;
			cin >> engineSize;

			if (engineSize > 8) {
				cout << "Damn you have the biggest engine in the world, are you sure you put in the right value? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Alright then we'll move on to cylinders" << endl;
					break;
				}

				else if (answer == 'n') {
					cout << "Alright provide your new answer" << endl;
					cin >> engineSize;
				}

				else {
					cout << "Not an actual answer try again" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;
		}
		cin.clear();


		//Amount of cylinders
		while (true) {
			cout << "Secondly how many cylinders should it have?" << endl;
			cin >> cylinders;

			if (cylinders > 8) {
				cout << "That's a lot of cylinders are you sure about this? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Alright moving on to the next section" << endl;
					break;
				}

				else if (answer == 'n') {
					cout << "Alright provide your new answer" << endl;
					cin >> cylinders;
				}

				else {
					cout << "Not an actual answer try again" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;
		}
		cin.clear();


		//Body width
		while (true) {
			cout << "Okay so now we're going to need the width in meters" << endl;
			cin >> inWidth;

			if (inWidth > 2) {
				cout << "Alright you got a big car huh, but I respect it, but still, do you want to change it? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Want would you like to change the width to?" << endl;
					cin >> inWidth;
					break;
				}

				else if (answer == 'n') {
					cout << "Alright perfect, moving on to length" << endl;
					break;
				}

				else {
					cout << "Not an actual answer try again" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;
		}
		cin.clear();


		//Body length
		while (true) {
			cout << "Now we're going to need the length in meters" << endl;
			cin >> inLength;

			if (inLength > 5) {
				cout << "Alright thats a long car, limousine? do you want to change it? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Want do you want to change it to?" << endl;
					cin >> inLength;
				}

				else if (answer == 'n') {
					cout << "Aight perfect, moving on to height" << endl;
					break;
				}

				else {
					cout << "Not a valid answer, try again" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;
		}
		cin.clear();


		//Body height
		while (true) {
			cout << "Now how tall should it be?" << endl;
			cin >> inHeight;

			if (inHeight > 2) {
				cout << "Now thats a tall car! Would you like to change it? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Alright what would you like to change it to?" << endl;
					cin >> inHeight;
				}

				else if (answer == 'n') {
					cout << "Alright lets move on to the colour" << endl;
					break;
				}

				else {
					cout << "Not a valid answer, try again" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;
		}
		cin.clear();


		//Body colour
		attempts = 0;
		cout << "What colour do you want the car to be?" << endl;
		while (true) {
			cin >> inColour;
			bool hasDigit = false;

			for (int i = 0; i < inColour.length(); i++) {

				for (char c : inColour) {

					if (isdigit(c)) {

						hasDigit = true;
						break;
					}
				}

				if (!hasDigit) {
					cout << "Happy with the colour? Y/N" << endl;
					cin >> answer;
					answer = tolower(answer);

					if (answer == 'y') {
						cout << "Alright lets move on to the model" << endl;
						break;
					}

					else if (answer == 'n') {
						cout << "What would you like to change it to?" << endl;
						cin >> inColour;
					}

					else {
						cout << "Not a valid answer, try again" << endl;
						cin.clear();
					}
				}

				else if (hasDigit) {
					attempts++;
					if (attempts == 3) {
						cout << "Aight no colour no car." << endl;
						return -1;
					}

					cout << "\nJust say a colour man: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;
		}
		cin.clear();


		//Body model
		attempts = 0;
		cout << "What model do you want the car to be?" << endl;
		while (true) {
			cin >> inModel;
			for (int i = 0; i < inModel.length(); i++) {
				bool hasDigit = false;

				for (char c : inModel) {

					if (isdigit(c)) {
						hasDigit = true;
						break;
					}
				}

				cout << "Happy with the model? Y/N" << endl;
				cin >> answer;
				answer = tolower(answer);

				if (answer == 'y') {
					cout << "Alright lets move on to the last part, where we need some information from you" << endl;
					break;
				}

				else if (answer == 'n') {
					cout << "What would you like to change it to?" << endl;
					cin >> inModel;
					cout << "Great! Now we just need some info from you" << endl;
					break;
				}

				else {
					cout << "Not a valid answer, try again" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;
		}
	}

	else { //if the user puts anything but 2 or 4 wheels
		cout << "Well unfortunately we haven't covered vehicles with " << numberOfWheels << " amount of wheels yet, our sincere apologies for this" << endl;
		cout << "You will get a sample of the sort of questions you will get once you choose a better wheel number" << endl;
		cout << "\nIf don't you want to write in the diameters for " << numberOfWheels << " number of wheels just say N/No, otherwise say Y/Yes" << endl;
		cin >> answer;

		if (answer == 'n') {
			cout << "Better luck next time!" << endl;
			return 0;
		}

		else {
			for (int i = 0; i < numberOfWheels; ++i) { //Dynamically allocated array for the wheelDiameters
				cout << "\nEnter the wheel dimension for wheel " << i + 1 << ": ";
				cin >> wheelDiameters[i];
				if (wheelDiameters == 0) {
					return 0;
				}
			}
		}
		cout << "You can sign up for the newsletter still but we just need a bit of information from you Y/Yes" << endl << "if you don't want to, type exit" << endl;
		cin >> signUp;

		for (char& c : signUp) {
			c = tolower(c);
		}

		if (signUp == "exit") {
			cout << "Understandable have a nice day!" << endl;
			return -1;
		}
	}
	cin.clear();


	//Owner name
	while (true) {
		cout << "What's your name?" << endl;
		cin >> inName;
		cout << "Are you sure you put in the correct name? Y/N" << endl;
		cin >> answer;
		answer = tolower(answer);

		if (answer == 'y') {
			break;
		}

		else if (answer == 'n') {
			cout << "What would you like to change it to?" << endl;
			cin >> inName;
			break;
		}

		else {
			cout << "Just Y/Yes or N/No please" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cin.clear();


	//Owner address
	while (true) {
		cout << "Now we need your address" << endl;
		cin >> inAddress;
		cout << "Are you sure this is the correct address? Y/N" << endl;
		cin >> answer;
		answer = tolower(answer);

		if (answer == 'y') {
			cout << "Alright then we're almost done!" << endl;
			break;
		}

		else if (answer == 'n') {
			cout << "What would you like to change it to?" << endl;
			cin >> inName;
			break;
		}

		else {
			cout << "Just Y/Yes or N/No please" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cin.clear();


	//Has to be used for the bool instructions criteria
	while (true) {
		cout << "Did you pass your drivers license exams? Y/N" << endl;
		cin >> answer;
		answer = tolower(answer);

		if (answer == 'y') {
			allowedToDrive = true;
			break;
		}

		else if (answer == 'n') {
			break;
		}

		else {

			if (count == 1) {
				return allowedToDrive;
				break;
			}
			cout << "If you fail to answer again then we'll assume you're avoiding the question and say you're not allowed to drive" << endl;
			count++;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
	}

	if (allowedToDrive) {
		cout << "Okay the documents are in order, you are allowed to drive!" << endl;
	}

	else if (!allowedToDrive) {
		cout << "Gotta work on that license before you get your dream car" << endl;
	}

	Engine* carEngine = new Engine(engineSize, cylinders);
	Body* carBody = new Body(inWidth, inLength, inHeight, inColour);
	Owner* carOwner = new Owner(inName, inAddress, allowedToDrive);
	MotorVehicle car(carEngine, carBody, carOwner, wheelDiameters, numberOfWheels, inModel);
	car.print();


}