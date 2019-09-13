#ifndef CARD_H
#define CARD_H
// Cory Reardon
// CECS 282-05
// Proj 1 - Solitaire Prime
// Due 9/17/2019
class Card {
private:
	char mRank;
	char mSuit;
public:
	Card();
	int getValue();
	void setRank(char);
	void setCard(char, char);
	void showCard();
};
#endif
