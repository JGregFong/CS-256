//BigNumbers.h
#pragma once
#include <string>
#include <vector>

using namespace std;

/**
* A BigNumbers class. A class that can have 10,000 digits as a number. Keep in mind that
* this class cannot do negative numbers.
*/


class BigNumbers {
private:
	//! A vector.
	/*! A vector that stores the digits of BigNumbers as chars. */
	vector <char> number;
public:

	//!Default Constructor for BigNumbers. 
	/*! Default BigNumbers can be set by setBigNum(string num). */
	///\sa BigNumbers(), setBigNum(), ToString()
	BigNumbers();

	//!A constructor for BigNumbers. 
	/*!Accepts a string in its constructor to create a BigNumbers object.*/
	///\param num a string argument.
	BigNumbers(string num);

	//!A function that takes a BigNumbers object and returns a string. 
	/*!Converts a BigNumbers object into a string.*/
	///\param other a BigNumbers argument.
	string ToString();

	//!A function that sets the BigNumbers taking in an argument. 
	/*!Sets BigNumbers object with a value stored in vector. */
	///\param num a string argument
	void setBigNum(string num);

	//!An overloaded operator. 
	/*!This operator adds one BigNumbers operator with another to produce
	a BigNumbers object result.*/
	///\param &other BigNumbers the right hand BigNumbers object.
	BigNumbers operator +(BigNumbers &other);

	//!An overloaded operator. 
	/*!This operator adds one BigNumbers operator with an integer to produce
	a BigNumbers object result. */
	///\param &other BigNumbers the right hand BigNumbers object.
	BigNumbers operator +(int other);

	//!An overloaded operator. 
	/*!This operator subtracts one BigNumbers operator with another to produce
	///a BigNumbers object result. */
	///\param &other BigNumbers the right hand BigNumbers object.
	BigNumbers operator -(BigNumbers &other);

	//!An overloaded operator. 
	/*!This operator subtracts one BigNumbers operator with an integer to produce
	a BigNumbers object result.*/
	///\param &other BigNumbers the right hand BigNumbers object.
	BigNumbers operator - (int other);

	//!An overloaded operator. 
	/*!This operator multiplies one BigNumbers operator with another to produce
	a BigNumbers object result.*/
	///\param &other BigNumbers the right hand BigNumbers object.
	BigNumbers operator *(BigNumbers &other);

	//!An overloaded operator. 
	/*!This operator multiplies one BigNumbers operator with an integer to produce
	a BigNumbers object result.*/
	///\param other an integer for multiplication with BigNumbers.
	BigNumbers operator * (int other);


	//!An overloaded operator. 
	/*!This operator divides one BigNumbers operator with an integer to produce
	a BigNumbers object result.*/
	///\param other an integer for dividing with BigNumbers.
	BigNumbers operator/(int other);


	//!An overloaded operator. 
	/*!This operator mods one BigNumbers operator with an integer to produce
	a BigNumbers object result.*/
	///\param other an integer for modulo with BigNumbers.
	BigNumbers operator %(int other);



	///A destructor for BigNumbers.
	~BigNumbers();
};


