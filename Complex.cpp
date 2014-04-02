//  Complex.cpp : complex numbers      

//  Member function definition file for complex numbers 
//  Programmed by: Dr. Monisha Pulimood
//  Modified by: Walter Michelin

//  ** Add your maintenance documentation where appropriate **

#include "Complex.h"
#include <iostream>
#include <iomanip>

using namespace std;

// add method definitions as needed

Complex::Complex (float r, float i)
{
	real = r;
	imag = i;
}

Complex::Complex(float r)
{
	real = r;
	imag = 0;
}

Complex::Complex()
{
	real = 0;
	imag = 0;
}

Complex Complex::operator+(const Complex &rhs) const
{
	Complex result;
	result.real = real + rhs.real;
	result.imag = imag + rhs.imag;
	return result;
}

Complex Complex::operator+(float lhs)
{
	Complex result;
	result.real = real + lhs;
	result.imag = imag;

	return result;
}

bool operator==(const Complex &lhs, const Complex &rhs)
{
	return(lhs.real == rhs.real && lhs.imag == rhs.imag);
}


Complex operator+(const float &lhs, const Complex &rhs)
{
	Complex result;
	result.real = lhs + rhs.real;
	result.imag = rhs.imag;

	return result;
}

istream &operator>>(istream &in, Complex &rhs)
{
	in >> rhs.real;
	in >> rhs.imag;

	return in;
}

ostream &operator<<(ostream &out, Complex rhs)
{
	if(rhs.real != 0 && rhs.imag != 0)
	{
		if(rhs.imag < 0)
		{
			out << rhs.real << rhs.imag << "i";

		}
		else
			out << rhs.real << "+" << rhs.imag << "i";
	}
	else if(rhs.real == 0 && rhs.imag != 0)
		out << rhs.imag << "i";
	else if(rhs.real != 0 && rhs.imag == 0)
		out << rhs.real;
	else
		out << rhs.real; 

	return out;
}