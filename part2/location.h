/////////////////////////////////////////////////////////////////////////////////////
// Location.h, The header file for the code contains functions and members         //
// the header Location.h                                                           //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


#ifndef LOCATION_H
#define LOCATION_H


#include<iostream>
#include<vector>					
#include<string>
#include "Point.h"                // include the header file
#include "Set.h"
using namespace std;


class location
{
public:
	// default constructor
	location();

	//As it is shown, Location is an enum
	enum LOCATION { NOT_FOUND, NEWYORK, SANFRANSISCO, LOSANGELES, CHICAGO };
	//it consider the type of function getlocation and prototype 
	LOCATION GetLocation(point &);

	//and here we have the data members
private:
	//object private members
	set NY_SetX;
	set NY_SetY;
	set SF_SetX;
	set SF_SetY;
	set LA_SetX;
	set LA_SetY;
	set CH_SetX;
	set CH_SetY;
};

#endif