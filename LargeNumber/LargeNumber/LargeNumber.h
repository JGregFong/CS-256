//LargeNumber.h
#pragma once
#include <string>
#ifndef LargeNumber.h
#ifdef LargeNumber.h


using namespace std;

class LargeNumber {
private:
	vector <char> number;
public:
	LargeNumber();
	LargeNumber(string num);
	void CreateNumber(string num);

	LargeNumber operator +(const LargeNumber &other) const;
	LargeNumber operator -(const LargeNumber &other) const;
	LargeNumber operator *(const LargeNumber &other) const;
	LargeNumber operator /(const LargeNumber &other) const;
	LargeNumber operator %(const LargeNumber &other) const;


	~LargeNumber();
};

#endif // !LargeNumber.h

