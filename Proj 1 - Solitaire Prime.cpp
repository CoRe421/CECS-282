#include <iostream>
using namespace std;
#include "Deck.h"
#include "Card.h"

void printMenu() {
	cout << "1. New Deck" << endl;
	cout << "2. Display Deck" << endl;
	cout << "3. Shuffle Deck" << endl;
	cout << "4. Play Solitaire Prime" << endl;
	cout << "5. Exit" << endl;
}

void startGame(Deck userDeck) {
	int primePiles = 0;
	cout << endl;
	while (userDeck.cardsLeft() > 0) {
		int count = 0;
		bool isPrime = false;
		while (isPrime == false && userDeck.cardsLeft() > 0) {
			Card c = userDeck.deal();
			count += c.getValue();
			bool divisorFound = false;
			if (count == 1) {
				c.showCard();
				cout << ", ";
				divisorFound = true;
			}
			for (int i = 2; i < count / 2; i++) {
				if (count % i == 0) {
					c.showCard();
					cout << ", ";
					divisorFound = true;
					break;
				}
			}
			if (divisorFound == true) {
				isPrime = false;
			}
			else {
				isPrime = true;
				c.showCard();
				primePiles++;
			}
		}
		if (userDeck.cardsLeft() == 0 && isPrime == false) {
			cout << "Loser" << endl << endl;
		}
		else if (userDeck.cardsLeft() == 0 && isPrime == true) {
			cout << " Prime:" << count << endl << endl;
			cout << "Winner in " << primePiles << " piles!" << endl;
		}
		else {
			cout << " Prime:" << count << endl;
		}
	}
}

int main() {
	cout << "Welcome to Solitaire Prime!" << endl;
	printMenu();
	int userChoice;
	cin >> userChoice;
	while (userChoice == 2 || userChoice == 3 || userChoice == 4) {
		cout << "You need to create a new deck first!" << endl;
		cin >> userChoice;
		if (userChoice == 1) {
			cout << "Your deck has been created." << endl;
		}
	}
	Deck userDeck;
	while (userChoice != 5) {
		if (userChoice == 1) {
			userDeck.refreshDeck();
		}
		else if (userChoice == 2) {
			userDeck.showDeck();
		}
		else if (userChoice == 3) {
			userDeck.shuffle();
		}
		else {
			startGame(userDeck);
		}
		cout << endl << "What would you like to do?" << endl;
		printMenu();
		cin >> userChoice;
	}
	cout << "Goodbye!";
	return 0;
}