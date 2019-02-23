/////////////////////////////////////////////////////////////////////////////////////
// Set.h, The header file for the code contains functions and members              //
// the header Set.h                                                                //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#ifndef SET_H
#define SET_H

class Set
{
public:
	Set();
	Set(vector<bool> &v);			// Constructor that will set the vector
	bool IsMember(int);			    // tracks whether the coordianate is in that position 
	Set Union(Set &);              // Union and Intersection operations
	Set Intersection(Set &);
	void Print();					// Prints the union and intersectin sets

private:
	vector<bool> coordinate;
};

#endif