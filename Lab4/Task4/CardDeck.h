#pragma once
#include "Card.h"


class CardDeck{
private:
	Card* deck;
	int amountOfCards = 0;
public:
	CardDeck();
	~CardDeck();
};

