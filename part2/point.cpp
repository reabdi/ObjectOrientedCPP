/////////////////////////////////////////////////////////////////////////////////////
// Point.cpp, The header file for the code contains functions and members          //
// the header Point.h                                                              //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////

# include <iostream>
using namespace std;
#include "Point.h"                            // include the header file


//default constructor
point::point()
{
	int x = 0;
	int y = 0;
}

//initilizing parameter constructor for the object
point::point(int xValue, int yValue)
{

	x = xValue;
	y = yValue;
}

//definition of functions for getting and setting the x and y coordinates
void point::SetY(int yValue) 
{
	y = yValue;
}

void point::SetX(int xValue)
{
	x = xValue;
}

int point::GetX() 
{
	return x;
}

int point::GetY() 
{
	return y;
}
