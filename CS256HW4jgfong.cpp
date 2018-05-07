// CS256HW4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstdlib> // For rand and srand 
#include <ctime>

using namespace std;

void GameOf21();

int main()
{
    return 0;
}

class Die {
private:
	int sides;
	int value;
public:
	Die() {
		int numSides = 6;
		unsigned seed = time(0);
		srand(seed);
		sides = numSides;
		roll();
	}
	Die(int numSides) {
		unsigned seed = time(0);
		srand(seed);
		sides = numSides;
		roll();
	}
	void roll() {
		const int MIN_VALUE = 1;
		value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;

	}
	int getSides() {
		return sides;
	}
	int getValue() {
		return value;
	}

};

void GameOf21() {
	int score = 0;
	bool rollAgain = true;
	Die die1(6), die2(6);
	cout << "Welcome to Game of 21." << endl;
	do {
		score = die1.getValue() + die2.getValue();
	} while (score <= 21 && score > 0 || rollAgain == true);
}

