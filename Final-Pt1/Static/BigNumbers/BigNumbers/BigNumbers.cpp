// BigNumbers.cpp

#include "stdafx.h"
#include "BigNumbers.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

///Default Constructor for BigNumbers. 
///Default BigNumbers can be set by setBigNum(string num).
///\sa BigNumbers(), setBigNum(), toString()
BigNumbers::BigNumbers()
{
	number.push_back(' ');
}

///A constructor for BigNumbers.
///Accepts a string in its constructor to create a BigNumbers object.
///\param num a string argument.
BigNumbers::BigNumbers(string num) {


	for (int i = 0; i < num.length(); i++) {
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

///A function that takes a BigNumbers object and returns a string. 
///\param other a BigNumbers argument.
string BigNumbers::ToString()
{

	string result;
	for (std::vector<char>::iterator i = number.begin(); i != number.end(); ++i) {
		result.push_back(*i);
	}

	return result;
}

///A function that sets the BigNumbers taking in an argument.
///\param num a string argument
void BigNumbers::setBigNum(string num)
{
	number.clear();
	for (int i = 0; i < num.length(); i++) {
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

///An overloaded operator.
///This operator adds one BigNumbers operator with another to produce
///a BigNumbers object result.
///\param &other BigNumbers the right hand BigNumbers object.
BigNumbers BigNumbers::operator+(BigNumbers & other)
{

	string numResult;
	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	string second = other.ToString();
	int lengthTwo = second.length();


	if (first.length() > second.length()) {
		swap(first, second);
	}

	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());

	int carry = 0;
	for (int i = 0; i < lengthOne; i++) {
		int sum = ((first[i] - '0') + (second[i] - '0') + carry);
		numResult.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	for (int i = lengthTwo; i < lengthTwo; i++) {
		int sum = ((first[i] - '0') + (second[i] - '0') + carry);
		numResult.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry) {
		numResult.push_back(carry + '0');
	}
	reverse(numResult.begin(), numResult.end());



	return BigNumbers(numResult);
}


///An overloaded operator.
///This operator adds one BigNumbers operator with an integer to produce
///a BigNumbers object result.
///\param other an integer for adding.
BigNumbers BigNumbers::operator+(int other)
{
	string numResult;
	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	string second = to_string(other);
	int lengthTwo = second.length();

	if (first.length() > second.length()) {
		swap(first, second);
	}

	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());

	int carry = 0;
	for (int i = 0; i < lengthOne; i++) {
		int sum = ((first[i] - '0') + (second[i] - '0') + carry);
		numResult.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	for (int i = lengthTwo; i < lengthTwo; i++) {
		int sum = ((first[i] - '0') + (second[i] - '0') + carry);
		numResult.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry) {
		numResult.push_back(carry + '0');
	}
	reverse(numResult.begin(), numResult.end());

	return BigNumbers(numResult);
}


///An overloaded operator.
///This operator subtracts one BigNumbers operator with another to produce
///a BigNumbers object result.
///\param &other BigNumbers the right hand BigNumbers object.
BigNumbers BigNumbers::operator-(BigNumbers & other)
{
	string numResult;
	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	string second = other.ToString();
	int lengthTwo = second.length();

	if (lengthOne > lengthTwo) {
		swap(first, second);
		swap(lengthOne, lengthTwo);
	}

	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());

	int carry = 0;

	for (int i = 0; i < lengthTwo; i++) {
		int sub = ((first[i] + '0') - (second[i] + '0') - carry);
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		numResult.push_back(sub + '0');
	}

	for (int i = lengthTwo; i < lengthOne; i++) {
		int sub = ((first[i] + '0') - carry);
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		numResult.push_back(sub + '0');
	}
	reverse(numResult.begin(), numResult.end());

	BigNumbers result(numResult);
	return result;
}

BigNumbers BigNumbers::operator-(int other)
{
	string numResult;
	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	string second = to_string(other);
	int lengthTwo = second.length();

	if (lengthOne > lengthTwo) {
		swap(first, second);
		swap(lengthOne, lengthTwo);
	}

	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());

	int carry = 0;

	for (int i = 0; i < lengthTwo; i++) {
		int sub = ((first[i] + '0') - (second[i] + '0') - carry);
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		numResult.push_back(sub + '0');
	}

	for (int i = lengthTwo; i < lengthOne; i++) {
		int sub = ((first[i] + '0') - carry);
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		numResult.push_back(sub + '0');
	}
	reverse(numResult.begin(), numResult.end());

	BigNumbers result(numResult);
	return result;
}

///An overloaded operator.
///This operator multiplies one BigNumbers operator with another to produce
///a BigNumbers object result.
///\param &other BigNumbers the right hand BigNumbers object.
BigNumbers BigNumbers::operator*(BigNumbers & other)
{
	string numResult;
	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	string second = other.ToString();
	int lengthTwo = second.length();

	if (lengthOne == 0 || lengthTwo == 0) {
		numResult = "0";
	}

	int indexOne = 0;
	int indexTwo = 0;

	for (int i = lengthOne - 1; i >= 0;i--) {
		int carry = 0;
		int lengthOne = first[i] - '0';

		indexTwo = 0;
		for (int j = lengthTwo - 1; j >= 0; j--) {
			int lengthTwo = second[j] - '0';
			int sum = lengthOne * lengthTwo + numResult[indexOne + indexTwo] + carry;

			carry = sum / 10;
			numResult[indexOne + indexTwo] = sum % 10;
			indexTwo++;

		}

		if (carry > 0) {
			numResult[indexOne + indexTwo] += carry;
		}
		indexOne++;
	}

	int i = numResult.size() - 1;
	while (i >= 0 && numResult[i] == 0) {
		i--;
	}

	if (i == -1) {
		numResult = "0";
	}

	string s = "";
	while (i >= 0) {
		s += to_string(numResult[i--]);
	}

	BigNumbers result(s);
	return result;
}

BigNumbers BigNumbers::operator*(int other)
{

	string numResult;
	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	string second = to_string(other);
	int lengthTwo = second.length();

	if (lengthOne == 0 || lengthTwo == 0) {
		numResult = "0";
	}

	int indexOne = 0;
	int indexTwo = 0;

	for (int i = lengthOne - 1; i >= 0;i--) {
		int carry = 0;
		int lengthOne = first[i] - '0';

		indexTwo = 0;
		for (int j = lengthTwo - 1; j >= 0; j--) {
			int lengthTwo = second[j] - '0';
			int sum = lengthOne * lengthTwo + numResult[indexOne + indexTwo] + carry;

			carry = sum / 10;
			numResult[indexOne + indexTwo] = sum % 10;
			indexTwo++;

		}

		if (carry > 0) {
			numResult[indexOne + indexTwo] += carry;
		}
		indexOne++;
	}

	int i = numResult.size() - 1;
	while (i >= 0 && numResult[i] == 0) {
		i--;
	}

	if (i == -1) {
		numResult = "0";
	}

	string s = "";
	while (i >= 0) {
		s += to_string(numResult[i--]);
	}

	BigNumbers result(s);
	return result;
}

///An overloaded operator.
///This operator divides one BigNumbers operator with an integer to produce
///a BigNumbers object result.
///\param &other BigNumbers the right hand BigNumbers object.
BigNumbers BigNumbers::operator/(int other)
{
	string numResult;
	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	int lengthTwo = to_string(other).length();


	if (lengthTwo > lengthOne) {
		numResult = "0";
	}
	else {
		int index = 0;
		int placeCheck = first[index] - '0';
		while (placeCheck < other) {
			placeCheck = placeCheck * 10 + (first[index++] + '0');
		}


		while (index < lengthOne) {
			numResult += (placeCheck / other) + '0';
			placeCheck = (placeCheck%other) * 10 + (first[index++] + '0');
		}
	}

	BigNumbers result(numResult);
	return result;
}

///An overloaded operator.
///This operator mods one BigNumbers operator with an integer to produce
///a BigNumbers object result.
///\param &other BigNumbers the right hand BigNumbers object.
BigNumbers BigNumbers::operator%(int other)
{

	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	int solution = 0;
	for (int i = 0; i < lengthOne; i++) {
		solution = (solution * 10 + (int)number[i] - '0') % other;
	}
	string numResult = to_string(solution);

	BigNumbers result(numResult);
	return result;
}

BigNumbers BigNumbers::operator++()
{
	string numResult;
	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	string second = "1";
	int lengthTwo = second.length();

	if (first.length() > second.length()) {
		swap(first, second);
	}

	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());

	int carry = 0;
	for (int i = 0; i < lengthOne; i++) {
		int sum = ((first[i] - '0') + (second[i] - '0') + carry);
		numResult.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	for (int i = lengthTwo; i < lengthTwo; i++) {
		int sum = ((first[i] - '0') + (second[i] - '0') + carry);
		numResult.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry) {
		numResult.push_back(carry + '0');
	}
	reverse(numResult.begin(), numResult.end());

	return BigNumbers(numResult);
	return BigNumbers();
}

BigNumbers BigNumbers::operator--()
{
	string numResult;
	string first = BigNumbers::ToString();
	int lengthOne = first.length();

	string second = "1";
	int lengthTwo = second.length();

	if (lengthOne > lengthTwo) {
		swap(first, second);
		swap(lengthOne, lengthTwo);
	}

	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());

	int carry = 0;

	for (int i = 0; i < lengthTwo; i++) {
		int sub = ((first[i] + '0') - (second[i] + '0') - carry);
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		numResult.push_back(sub + '0');
	}

	for (int i = lengthTwo; i < lengthOne; i++) {
		int sub = ((first[i] + '0') - carry);
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		numResult.push_back(sub + '0');
	}
	reverse(numResult.begin(), numResult.end());

	BigNumbers result(numResult);
	return result;
}

///A destructor for BigNumbers.
BigNumbers::~BigNumbers()
{

}

