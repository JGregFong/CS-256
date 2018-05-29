//LargeNumber.h
#pragma once
#include <string>
#include <vector>
using namespace std;



class LargeNumber {
private:
	vector <char> number;
public:
	LargeNumber();
	LargeNumber(string num);

	string ToString(LargeNumber other);

	LargeNumber operator +(const LargeNumber &other) const;
	LargeNumber operator -(const LargeNumber &other) const;
	LargeNumber operator *(const LargeNumber &other) const;
	LargeNumber operator /(const LargeNumber &other) const;
	LargeNumber operator %(const LargeNumber &other) const;


	~LargeNumber();
};


