// jgfongCS256HW4.cpp : Defines the entry point for the console application.
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
	cout << "Welcome to jgfong's CS256 HW4 Program." << endl;
	cout << "1.) Game Of 21 with d6s" << endl;
	cout << "2.) Parking Ticket Sim" << endl;
	cout << "3.) Ship, Cruise, Cargo Ship" << endl;
	int choice;

	cin >> choice;

	switch (choice) {
	case 1:
		GameOf21();
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}


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
	int playerScore = 0;
	int comScore = 0;
	bool rollAgain = true;
	Die die1(6), die2(6);
	cout << "Welcome to Game of 21." << endl;
	cout << "The Player's d6 has been rolled." << endl;
	cout << "The Computer's d6 has been rolled." << endl;


	do {
		playerScore += die1.getValue();
		comScore += die2.getValue();
		string response;
		cout << "Results:" << endl;
		cout << "Die Rolled : " << die1.getValue() << endl;
		cout << ", Current Score: " << playerScore << endl;
		cout << "Do you wish to roll again? (Y/N): ";
		cin >> response;
		if (response == "N" || response == "n" || response == "No" || response == "no" || response == "NO") {
			rollAgain = false;
		}
		if (response == "Y" || response == "y" || response == "YES" || response == "Yes" || response == "yes") {
			die1.roll();
			die2.roll();
		}

	} while (playerScore <= 21 && rollAgain == true || comScore <= 21 && rollAgain == true);

	cout << "Scores:" << endl;
	if (playerScore > 21 || comScore >21) {
		if (playerScore > 21 && comScore <= 21) {
			cout << "Player is over 21. Computer Wins!" << endl;
			cout << "Player: " << playerScore << " Computer: " << comScore << endl;
		}
		else if (comScore > 21 && comScore <= 21) {
			cout << "Computer is over 21. Player Wins!" << endl;
			cout << "Player: " << playerScore << " Computer: " << comScore << endl;
		}
		else {
			cout << "Computer and Player are over 21. Draw!" << endl;
			cout << "Player: " << playerScore << " Computer: " << comScore << endl;
		}
	}
	else if (playerScore == comScore) {
		cout << "Player and Computer have same score. Draw!" << endl;
		cout << "Player: " << playerScore << " Computer: " << comScore << endl;
	}

	else{
		if (playerScore > comScore) {
			cout << "Player wins!" << endl;
		}
		else {
			cout << "Computer wins!" << endl;
		}
	cout << "Player: " << playerScore << " Computer: " << comScore << endl;
	}


}

class ParkedCar {
private:
	string make;
	string model;
	string color;
	int licenseNumber;
	int minutes;

public:
	ParkedCar() {
		make = "";
		model = ""; 
		color = "";
		licenseNumber = 0;
		minutes = 0;
	}

	ParkedCar(string name, string version, string tint, int num, int min) {
		make = name;
		model = version;
		color = tint;
		licenseNumber = num;
		minutes = min;
	}

	void setMake(string name) {
		make = name;
	}

	void setModel(string name) {
		model = name;
	}

	void setColor(string tint) {
		color = tint;
	}

	void setLicense(int number) {
		licenseNumber = number;
	}

	void setMinutes(int min) {
		minutes = min;
	}

	string getMake() {
		return make;
	}
	
	string getModel() {
		return model;
	}

	string getColor() {
		return color;
	}

	int getLicenseNum() {
		return licenseNumber;
	}

	int getMinutes() {
		return minutes;
	}

};

class ParkingMeter {
private:
	int purchasedMinutes;
public:
	int getPurchasedMinutes() {
		return purchasedMinutes;
	}
};

class ParkingTicket {
private:

public:
	string getMake(ParkedCar &car) {
		return car.getMake();
	}

	string getModel(ParkedCar &car) {
		return car.getModel();
	}

	string getColor(ParkedCar &car) {
		return car.getColor();
	}

	int getLicenseNum(ParkedCar &car) {
		return car.getLicenseNum();
	}

	int getMinutes(ParkedCar &car) {
		return car.getMinutes();
	}
};

class PoliceOfficer {
private:
	string name;
	int badgeNumber;

public:
	PoliceOfficer(string designation, int number) {
		name = designation;
		badgeNumber = number;
	}
};

void TicketGiven() {

}

