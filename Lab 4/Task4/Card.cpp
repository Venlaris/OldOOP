#include "Card.h"
#include <iostream>

using namespace std;

Card::Card() {}

Card::Card(int initNumSuit, int initNumRank) : numRank(initNumRank), numSuit(initNumSuit) {

	//srand(time(nullptr)); failed attempt to make a randomizer
	//random numSuit

	//card suits
	if (numSuit == 1) {
		suit = "Clubs";
	}

	if (numSuit == 2) {
		suit = "Diamonds";
	}

	else if (numSuit == 3) {
		suit = "Hearts";
	}

	else if (numSuit == 4) {
		suit = "Spades";
	}

	else if (numSuit == 5) { 
		suit = "joker";
		rank = "It's a ";
	}
	


	//////////////////////////////////////////


	
	//card values
	if (numRank == 1) {
		rank = "Ace of ";
	}

	else if (numRank == 2) {
		rank = "Twos of ";
	}

	else if (numRank == 3) {
		rank = "Threes of ";
	}

	else if (numRank == 4) {
		rank = "Fours of ";
	}

	else if (numRank == 5) {
		rank = "Fives of ";
	}

	else if (numRank == 6) {
		rank = "Six of ";
	}

	else if (numRank == 7) {
		rank = "Sevens of ";
	}

	else if (numRank == 8) {
		rank = "Eights of ";
	}

	else if (numRank == 9) {
		rank = "Nines of ";
	}

	else if (numRank == 10) {
		rank = "Tens of ";
	}

	else if (numRank == 11) {
		rank = "The Jack of ";
	}

	else if (numRank == 12) {
		rank = "The Queen of ";
	}

	else if (numRank == 13) {
		rank = "The King of ";
	}

	

}

void Card::Print() {
	cout << rank << suit << endl;
}