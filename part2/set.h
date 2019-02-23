/////////////////////////////////////////////////////////////////////////////////////
// set.h, The header file for the code contains functions and members              //
// the header set.h                                                                //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#ifndef set_H
#define set_H

class set
{
public:
	set();
	set(vector<bool> &v);			// Constructor that will set the vector
	bool IsMember(int);			    // tracks whether the coordianate is in that position 
	set Union(set &);              // Union and Intersection operations
	set Intersection(set &);
	void Print();					// Prints the union and intersectin sets

private:
	vector<bool> coordinate;
};

#endif


