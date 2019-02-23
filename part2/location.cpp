/////////////////////////////////////////////////////////////////////////////////////
// Location.h, The header file for the code contains functions and members         //
// the header Location.h                                                           //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<vector>					
#include<string>
#include "Point.h"                // include the header file
#include "Location.h"
#include "Set.h"
using namespace std;

//initilizing default constructor
location::location()
{
	//initilize different vectors for each location
	vector<bool>NY{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	vector<bool>SF{ 0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 };
	vector<bool>LA{ 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0 };
	vector<bool>CH{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1 };

	NY_SetX = *new set(NY);
	NY_SetY = *new set(NY);
	SF_SetX = *new set(SF);
	SF_SetY = *new set(SF);
	LA_SetX = *new set(LA);
	LA_SetY = *new set(LA);
	CH_SetX = *new set(CH);
	CH_SetY = *new set(CH);
}



location::LOCATION location::GetLocation(point &p)
{
	LOCATION location;
	int x = p.GetX();
	int y = p.GetY();

	if (NY_SetX.IsMember(x) && NY_SetY.IsMember(y))        // check if x and y coordinates or new york belong to the set
		location = NEWYORK;
	else 
		if (SF_SetX.IsMember(x) && SF_SetY.IsMember(y))    // check if x and y coordinates orsan fransisco belong to the set
		location = SANFRANSISCO;
	else  
		if (LA_SetX.IsMember(x) && LA_SetY.IsMember(y))    // check if x and y coordinates or LosAngeles belong to the set
		location = LOSANGELES;
	else 
		if (CH_SetX.IsMember(x) && CH_SetY.IsMember(y))    // check if x and y coordinates or chicago belong to the set
		location = CHICAGO;
	else
		location = NOT_FOUND;
	return location;
}

