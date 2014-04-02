//Walter Michelin 4/1/14 Assignment 4

#include <iostream>
#include "Complex.h"

using namespace std;

class Set
{
	private:
		//Array to store complex objects
		Complex complexArray[100];
		//variable to keep track of the end of the wanted data
		int size;

	public:
		//default constructor
		Set();
		//checks if size == 0
		bool isEmpty();
		//checks if size == 100
		bool isFull();
		//adds complex object to end of set, increments size by 1
		void addToSet(const Complex&);
		//linearly checks to see if complex object is in set
		bool isInSet(const Complex&);
		//linearly searches set for complex object
		int getIndexOf(const Complex&);
		//assigns a set to a set
		void operator=(const Set&);
		//assigns a set to a complex number
		void operator=(const Complex&);
		//adds a set to a set
		Set operator+(const Set&);
		//adds a complex number to a set
		Set operator+(const Complex&);
		//finds the intersection of two sets
		Set operator*(Set&);
		//removes a complex number from a set
		Set operator-(Complex&);
		//adds a set to a complex number
		friend Set operator+(const Complex&, Set&);
		//outputs the set in the proper formatting
		friend ostream &operator<<(ostream&, Set&);
		//inputs given data into a set, works with either keyboard or file input
		friend istream &operator>>(istream&, Set&);
};