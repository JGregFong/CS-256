// InClassProject-5-22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
	string name;
	int number;
	string hireDate;


protected: 
	Employee(string n, int num, string date) {
		if (num >= 10000 || num<0) {
			throw InvalidEmployeeNum();
		}
		name = n;
		number = num;
		hireDate = date;
	}

public:
	class InvalidEmployeeNum {};
	Employee();
	void setName(string n){
		name = n;
	}
	void setNum(int num) {
		if (num >= 10000 || num<0) {
			throw InvalidEmployeeNum();
		}
		number = num;
	}
	void setHireDate(string date) {
		hireDate = date;
	}

	string getName() {
		return name;
	}

	int getNum() {
		return number;
	}

	string getHireDate() {
		return hireDate;
	}

};
Employee::Employee():name(""),number(0),hireDate("1900") {
	cout << "Default Employee created." << endl;
}

class ProductionWorker : public Employee {
private:
	int shift;
	double payRate;
	ProductionWorker();

protected:

public:

	ProductionWorker(string n, int num, string date, int shft, double pay) {
		setName(n);
		setNum(num);
		setHireDate(date);
		shift = shft;
		payRate = pay;
		
	}

	void setShift(int num) {
		shift = num;
	}

	void setPay(double pay) {
		payRate = pay;
	}

	int getShift() {
		return shift;
	}

	double getPay() {
		return payRate;
	}
};


int main()
{
	string name;
	int employeeNum;
	string hireDate;
	int shift;
	double pay;
	cout << "Welcome to the Employee Database." << endl;
	cout << "Please enter your employee name: ";
	cin >> name;
	cout << "\nPlease enter your employee number: ";
	cin >> employeeNum;
	cout << "\nPlease enter your Hire Date: ";
	cin >> hireDate;
	cout << "\nPlease enter your shift number(1 or 2):";
	cin >> shift;
	cout << "\nPlease enter your pay rate: $";
	cin >> pay;
	cout << "\nCreating employee profile......." << endl;
	try {
		ProductionWorker(name, employeeNum, hireDate, shift, pay);
	}
	catch (Employee::InvalidEmployeeNum error) {
		cout << "Employee number is outside expected parameters. Number is invalid.";
	}
	catch (int InvalidShift) {
		cout << "Invalid shift detected. Invalid input is: " << InvalidShift;
	}
	catch (string InvalidPayRate) {
		cout << InvalidPayRate;
	}


    return 0;
}

