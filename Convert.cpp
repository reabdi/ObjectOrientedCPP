// CIS 554
// By: Reza Abdi
// Assignment 1 

#include <iostream>
#include <cmath>		// this is included as power function is used
#include "Convert.h"	//the header file is included
using namespace std;

// defination of the constructor of the class 
Convert::Convert(int)
{
	baseNumber = 0;
	number = 0;
}

//Function Definition for accessing the number and base number
void Convert::convertInitiation()
{
	cout << "Please enter the base number" << endl;
	cin >> baseNumber;		//asking for the base number
	cout << "Please enter the Number which its digits are less than " << baseNumber << endl;
	cin >> number;			//asking for the desired number to convert to decimal
	int tester;				//a temporary variable to keep the number unchanged
	int digit;				//the variable to keep each digit of the number for accuracy checking
	tester = number;		
	while (tester > 0)		//loop for checking the digits
	{
		digit = tester % 10;
		if (digit < baseNumber)			//if the digit is less than base number
		{
			tester = tester / 10;
		}
		else
		{								//otherwise, the code will show an error message
			cout << "Please enter a correct numnber with digits less than " << baseNumber << endl;
			cin >> number;				// same process for the number to dubble check
			tester = number;
		}		//end if
	}			//end while
}				//end function

//Function Definition for calculating the decimal
void Convert::convertCalculation()
{
	int digit = 0;					//the variable to keep each digit
	int powerCounter = 0;			//variable for counting the power number
	int decimal = 0;				//the last answer
	while (number > 0)				//loop for checking the digits
	{
		digit = number % 10;
		decimal = decimal + digit * pow(baseNumber, powerCounter);
		powerCounter += 1;
		number = number / 10;
	}								//end while
	cout << "the decimal number is " << decimal << endl;			//last comment
}