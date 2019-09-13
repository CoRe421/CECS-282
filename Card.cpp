// Cory Reardon
// CECS 282-05
// Proj 1 - Solitaire Prime
// Due 9/17/2019

#include "Card.h"
#include <iostream>
using namespace std;

Card::Card() {
	mRank = 'A';
	mSuit = 'S';
}

void Card::setCard(char r, char s) {
	mRank = r;
	mSuit = s;
}

int Card::getValue() {
	if (mRank - '0' < 10) {
		return (int)mRank - '0';
	}
	else if (mRank == 'A') {
		return 1;
	}
	else {
		return 10;
	}
}

void Card::setRank(char r) {
	mRank = r;
}

void Card::showCard() {
	if (mRank == 'T') {
		cout << 10 << mSuit;
	}
	else {
		cout << mRank << mSuit;
	}
}