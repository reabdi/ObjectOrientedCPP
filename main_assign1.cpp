// CIS 554
// By: Reza Abdi
// Assignment 1 

#include<iostream>
#include "Convert.h"
using namespace std;

int main()
{
	Convert myConvert(0);				//creating the object of the class titled "myConvert"
	myConvert.convertInitiation();		//calling the first function to receive the numbers
	myConvert.convertCalculation();		//calling the function to convert the number to decimal
}