// Cory Reardon
// CECS 282-05
// Proj 1 - Solitaire Prime
// Due 9/17/2019

#include "Deck.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;
Deck::Deck() {
	mTop = 0;
	char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	char suits[] = { 'S','C','H','D' };
	for (int s = 0; s < 4; s++) {
		for (int r = 0; r < 13; r++) {
			mStorage[13 * s + r].setCard(ranks[r], suits[s]);
		}
	}
}

int Deck::cardsLeft() {
	return 52 - mTop;
}

void Deck::shuffle() {
	srand(time(0));
	for (int i = 0; i < 1000; i++) {
		int x = rand() % 52; // 0 - 51
		int y = rand() % 52;
		Card c = mStorage[x];
		mStorage[x] = mStorage[y];
		mStorage[y] = c;
	}
}

void Deck::showDeck() {
	if (mTop == 51) {
		mStorage[51].showCard();
	}
	else {
		int nextLine = 0;
		for (int i = mTop; i < 51; i++) {
			if (nextLine == 12) {
				mStorage[i].showCard();
				cout << endl;
				nextLine = 0;
			}
			else {
				mStorage[i].showCard();
				cout << ", ";
				nextLine++;
			}
		}
		mStorage[51].showCard();
	}
}

void Deck::refreshDeck() {
	mTop = 0;
	char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	char suits[] = { 'S','H','C','D' };
	for (int s = 0; s < 4; s++) {
		for (int r = 0; r < 13; r++) {
			mStorage[13 * s + r].setCard(ranks[r], suits[s]);
		}
	}
}

Card Deck::deal() {
	mTop++;
	return mStorage[mTop - 1];
}