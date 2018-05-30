// BigNumbers.h

#include "BigNumbers.h"
#include <string>
using namespace std;

BigNumbers::BigNumbers()
{

}

BigNumbers::BigNumbers(string num) {

	for (int i = 0; i < num.length; i++) {
		if (isdigit(num[i])) {
			number.push_back(num[i]);
		}
		else if (isalpha(num[i])) {
			throw "Alphabet letter detected.";
		}
		else {
			throw "Unidentified character detected.";
		}

	}
}

string BigNumbers::ToString(BigNumbers other)
{

	string result(other.number.begin(), other.number.end());

	
	return result;
}

BigNumbers operator +(BigNumbers &other) {
	BigNumbers result;
	return result;
}

BigNumbers BigNumbers::operator+(const BigNumbers & other) const
{
	BigNumbers result;
	return result;
}

BigNumbers BigNumbers::operator-(const BigNumbers & other) const
{
	BigNumbers result;
	return result;
}

BigNumbers BigNumbers::operator*(const BigNumbers & other) const
{
	BigNumbers result;
	return result;
}

BigNumbers BigNumbers::operator/(const BigNumbers & other) const
{
	BigNumbers result;
	return result;
}

BigNumbers BigNumbers::operator%(const BigNumbers & other) const
{
	BigNumbers result;
	return result;
}

BigNumbers::~BigNumbers()
{

}