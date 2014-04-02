//Walter Michelin 4/1/14 Assignment 4

#include <iostream>
#include <fstream>
#include "Set.h"

using namespace std;

Set::Set()
{
	size = 0;
}

void Set::addToSet(const Complex& rhs)
{
	if(!isInSet(rhs))
	{
		complexArray[size] = rhs;
		size++;
	}
}

int Set::getIndexOf(const Complex& rhs)
{
	for(int i = 0; i < size; i++)
	{
		if(complexArray[i] == rhs)
			return i;
	}
	
	return -1;
}

bool Set::isInSet(const Complex &rhs)
{
	bool inArray = false;

	for(int i = 0; i < size; i++)
	{
		if(complexArray[i] == rhs)
		{
			inArray = true;
		}
	}

	return inArray;

}

bool Set::isEmpty()
{
	return (size == 0);
}

bool Set::isFull()
{
	return (size == 100);
}

Set Set::operator-(Complex& rhs)
{
	Set temp = *this;

	int index = getIndexOf(rhs);
	if(index == -1)
	{
		return *this;
	}
	for(int i = index; i < temp.size - 1; i++)
	{
		temp.complexArray[i] = temp.complexArray[i + 1];
	}
	temp.complexArray[size-1] = Complex(); 
	temp.size--;

	return temp;

}

Set Set::operator*(Set& rhs)
{
	Set returnVal = Set();
	bool inSet = false;
	for(int i = 0; i < size; i++)
	{
		inSet = false;
		inSet = rhs.isInSet(complexArray[i]);
		if(inSet)
		{
			returnVal.addToSet(complexArray[i]);
		}
	}

	return returnVal;
}

void Set::operator=(const Set& rhs)
{
	for(int i = 0; i < 100; i++)
	{
		complexArray[i] = rhs.complexArray[i];
	}

	size = rhs.size;
}

void Set::operator=(const Complex& rhs)
{
	for(int i = 0; i < 100; i++)
	{
		complexArray[i] = Complex();
	}

	complexArray[0] = rhs;
	size = 1;
}

Set Set::operator+(const Set& rhs)
{
	Set returnVal = *this;

	for(int i = 0; i < rhs.size; i++)
	{
		if(!isInSet(rhs.complexArray[i]))
		{
			if(!returnVal.isFull())
			{	
				returnVal.complexArray[returnVal.size] = rhs.complexArray[i];
				returnVal.size++;
			}
		}
	}

	return returnVal;

}

Set Set::operator+(const Complex& rhs)
{
	Set returnVal = Set();
	for(int i = 0; i < size; i++)
	{
		returnVal.complexArray[i] = complexArray[i];
	}
	returnVal.size = size;
	if(!returnVal.isInSet(rhs))
	{
		returnVal.complexArray[returnVal.size] = rhs;
		returnVal.size++;
	}

	if(!isFull())
		return returnVal;


	return *this;
}

Set operator+(const Complex& lhs, Set& rhs)
{
	
	if(!rhs.isFull())
	{
		Set returnVal = Set();
		for(int i = 0; i < rhs.size; i++)
		{
				returnVal.complexArray[i + 1] = rhs.complexArray[i];
		}
		returnVal.size = rhs.size;
		returnVal.complexArray[0] = lhs;
		returnVal.size++;

		if(!(rhs.isInSet(lhs)))
			return returnVal;
	}

	return rhs;
}

istream &operator>>(istream &in, Set &rhs)
{
	int runs = 0;
	in >> runs;

	Complex temp = Complex();
	for(int i = 0; i < runs; i++)
	{
		in >> temp;
		if(!rhs.isInSet(temp))
			rhs.addToSet(temp);
		temp = Complex();
	}

	return in;
}

ostream &operator<<(ostream &out, Set &rhs)
{
	out << "{";

	for(int i = 0; i < rhs.size; i++)
	{
		out << rhs.complexArray[i];

		if(!(i == rhs.size - 1))
			out << ", ";
	}

	out << "}";
	return out;
}
