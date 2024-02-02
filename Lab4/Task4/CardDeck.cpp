#include "CardDeck.h"
#include <Iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>

using namespace	std;


CardDeck::CardDeck() {
	int cards = 55;
	int cardHand = 0;
	deck = new Card[cards];

	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 13; j++) {

			Card card;
			deck[amountOfCards] = Card(i, j);
			amountOfCards++;
		}
	}


	for (int i = 1; i < 4; i++) {

		deck[amountOfCards] = Card(5, 0);
		amountOfCards++;
	}

	//shuffle(deck, deck + cards, default_random_engine(random_device()())); //shuffles the carddeck so everything is in random order
	//cout << "How many cards do you want? ";
	//cin >> cardHand;
	//for (int i = 1; i < cardHand; i++) {             //this is used in case you want the user to say how many cards they want
	//	deck[i].Print();
	//	this_thread::sleep_for(chrono::seconds(1)); //using this so not every card gets displayed at once
	//	if (i == 12 || i == 25  || i == 38 || i == 51) {
	//		cout << "\n";
	//	}
	//}
	
	for (int i = 1; i < 55; i++) { //displays all the cards in random order
		deck[i].Print();
		this_thread::sleep_for(chrono::seconds(1));  //using this so not every card gets displayed at once
		if (i == 12 || i == 25  || i == 38 || i == 51) {
			cout << "\n";
		}
	}

}


CardDeck::~CardDeck() {
	delete[] deck;
}
