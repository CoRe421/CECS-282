#ifndef DECK_H 
#define DECK_H
#include "Card.h"
// Cory Reardon
// CECS 282-05
// Proj 1 - Solitaire Prime
// Due 9/17/2019
class Deck {
private:
	Card mStorage[52];
	int mTop;
public:
	Deck();
	void shuffle();
	void showDeck();
	int cardsLeft();
	void refreshDeck();
	Card deal();
};
#endif