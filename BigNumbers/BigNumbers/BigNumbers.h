//BigNumbers.h
#pragma once
#include <string>
#include <vector>
using namespace std;



class BigNumbers {
private:
	/**
	A vector.
	A vector that stores the digits of BigNumbers as chars.
	*/
	vector <char> number;
public:

	BigNumbers();
	BigNumbers(string num);

	string ToString(BigNumbers other);

	BigNumbers operator +(const BigNumbers &other) const;
	BigNumbers operator -(const BigNumbers &other) const;
	BigNumbers operator *(const BigNumbers &other) const;
	BigNumbers operator /(const BigNumbers &other) const;
	BigNumbers operator %(const BigNumbers &other) const;


	~BigNumbers();
};


