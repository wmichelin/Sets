//Walter Michelin 4/1/14 Assignment 4

#include <iostream>
#include <fstream>
#include "Set.h"
#include "Complex.h"

Set setA = Set();
Set setB = Set();
Set setC = Set();
Complex c1 = Complex();

void clear()
{
	setA = Set();
	setB = Set();
	setC = Set();	
	c1 = Complex();
}

int main()
{
	string filename;
	fstream fin;	
	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	filename = "1.2.txt";
	fin.open(filename);
	fin >> setB;
	fin.close();


	cout << "*1. Finding the union of two sets where the result has less than 100 elements " << endl;


	cout << "SET A: " << setA << endl;
	cout << "SET B: " << setB << endl;
	setC = setA + setB;
	cout << "The union of A and B: " << setC << endl << endl;

	clear();

	cout << "*2. Finding the union of two sets where the result has more than 100 elements " << endl;
	filename = "2.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	filename = "2.2.txt";
	fin.open(filename);
	fin >> setB;
	fin.close();

	cout << "SET A: " << setA << endl;
	cout << "SET B: " << setB << endl;
	setC = setA + setB;
	cout << "The union of A and B: " << setC << endl;
	cout << "As expected, only the first 100 elements were added. All subsequent elements' data is lost." << endl << endl;
	
	clear();

	cout << "*3. Finding the result of adding a complex number to a set, where the complex number is not in the set " << endl;
	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	c1 = Complex(6, 6);	
	setB = setA + c1;
	cout << "SET A: " << setA << endl;
	cout << "C1: " << c1 << endl;
	cout << "The result of adding c1 to setA: " << setB << endl << endl;

	clear();

	cout << "*4. Finding the result of adding a complex number to a set, where the complex number is in the set " << endl;
	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	c1 = Complex(1, 1);
	setB = setA + c1;
	cout << "SET A: " << setA << endl;
	cout << "C1: " << c1 << endl;
	cout << "The result of adding c1 to setA: " << setB << endl << endl;

	clear();

	cout << "*5. Finding the result of adding a set to a complex number, where the complex number is not in the set " << endl;
	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	c1 = Complex(6, 6);
	setB = c1 + setA;
	cout << "SET A: " << setA << endl;
	cout << "C1: " << c1 << endl;
	cout << "The result of adding setA to c1: " << setB << endl << endl;

	clear();

	cout << "*6. Finding the result of adding a set to a complex number, where the complex number is in the set " << endl;
	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	c1 = Complex(1, 1);
	setB = c1 + setA;
	cout << "SET A: " << setA << endl;
	cout << "C1: " << c1 << endl;
	cout << "The result of adding setA to c1: " << setB << endl;
	cout << "As expected, c1 was essentially ignored since it is already in setA. " << endl << endl;
	
	clear();

	cout << "*7. Finding the result of finding the intersection between two Sets with 5 similar elements " << endl;
	filename = "3.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	filename = "3.2.txt";
	fin.open(filename);
	fin >> setB;
	fin.close();

	cout << "SET A: " << setA << endl;
	cout << "SET B: " << setB << endl;
	setC = setA * setB;
	cout << "The intersection of A and B: " << setC << endl << endl;

	clear();

	cout << "*8. Finding the resut of finding the intersection between two sets with 0 similar elements " << endl;

	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	filename = "1.2.txt";
	fin.open(filename);
	fin >> setB;
	fin.close();

	cout << "SET A: " << setA << endl;
	cout << "SET B: " << setB << endl;
	setC = setA * setB;
	cout << "The intersection of A and B: " << setC << endl;
	cout << "As expected, since A and B have no similar elements, the intersection of the two sets is empty." << endl << endl;

	clear();

	cout << "*9. Finding the result of removing a complex number from a set, where the complex number is in the set " << endl;

	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	c1 = Complex(1, 1);

	cout << "SET A: " << setA << endl;
	cout << "C1: " << c1 << endl;
	setB = setA - c1;

	cout << "The result of c1 being removed from setA is: " << setB << endl << endl;

	clear();

	cout << "*10. Finding the result of removing a complex number from a set, where the complex number is not in the set " << endl;
	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	c1 = Complex(6, 6);

	cout << "SET A: " << setA << endl;
	cout << "C1: " << c1 << endl;
	setB = setA - c1;

	cout << "The result of c1 being removed from setA is: " << setB << endl;
	cout << "As expected, since c1 is not in setA, setA is unchaged." << endl << endl;

	clear();

	cout << "*11. Finding the result of assigning a set to different set " << endl;
	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	filename = "1.2.txt";
	fin.open(filename);
	fin >> setB;
	fin.close();

	cout << "Pre-assignment: " << endl;
	cout << "SET A: " << setA << endl;
	cout << "SET B: " << setB << endl;
	cout << "Set A = Set B" << endl;
	setA = setB;
	cout << "Post-assignment: " << endl;
	cout << "SET A: " << setA << endl;
	cout << "SET B: " << setB << endl << endl;

	clear();

	cout << "*12. Finding the result of assigning a set to a complex number " << endl;

	filename = "1.1.txt";
	fin.open(filename);
	fin >> setA;
	fin.close();
	c1 = Complex(6, 6);

	cout << "Pre-assignment: " << endl;
	cout << "SET A: " << setA << endl;
	cout << "C1: " << c1 << endl;
	cout << "Set A = c1" << endl;
	setA = c1;
	cout << "Post-assignment: " << endl;
	cout << "SET A: " << setA << endl;
	cout << "c1: " << c1 << endl << endl;

	clear();

	return 0;
}