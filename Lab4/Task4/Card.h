#pragma once
#include <string>



class Card {
private:
	std::string suit;
	std::string rank;

	int numSuit;
	int numRank;
	int jokers;

public:
	Card();
	Card(int initNumSuit, int initNumRank);
	void Print();

};

