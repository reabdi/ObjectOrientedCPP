// CIS 554
// By: Reza Abdi
// Assignment 1 
#include <iostream>
using namespace std;

// Class defination
class Convert
{
public:
	Convert(int);				//constructor of the code
	void convertInitiation();	//this function will get the base number and number and check the availability of converting to decimal
	void convertCalculation();	// for our calculations to convert to decimal
private:
	int baseNumber; //the base number which should be 2 through base 9
	int number;		//the initial number which the code needs to convert to decimal
};
