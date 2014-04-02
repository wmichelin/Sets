///  Complex.h : complex numbers

//  Class defintion for complex numbers 
//  Programmed by: Dr. Monisha Pulimood
//  Modified by: Walter Michelin

//  ** Add maintenance and interface documentation where appropriate **

#if ! defined (COMPLEX_H)
#define COMPLEX_H

#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
	private:
		float real;
		float imag;

	public:
		Complex(float, float);
		Complex(float);
		Complex();

		Complex operator+(const Complex&) const;
		Complex operator+(float);
		friend bool operator==(const Complex&, const Complex&);
		friend istream &operator>>(istream&, Complex&);
		friend ostream &operator<<(ostream&, Complex);
		friend Complex operator+(const float&, const Complex&);
};

#endif  // COMPLEX_H



