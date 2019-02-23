/////////////////////////////////////////////////////////////////////////////////////
// setTest.cpp, The header file for the code contains functions and members        //
// the header Set.h                                                                //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>							
#include "Set.h"
#include<string>
using namespace std;

void main()
{
	//initilizing 
	vector<bool>vector1(21, 0);

	for (int i = 0; i < 21; i = i + 2)
	{
		vector1[i] = 1;
	}

	// assign object and pass vector to object
	Set sample1(vector1);

	// print Set sample1
	cout << "showing sample 1" << endl;
	sample1.Print();

	//initilize vectors and objects sample2 
	vector<bool>vector2(21, 0);

	for (int i = 0; i < 21; i = i + 3)
	{
		vector2[i] = 1;
	}

	// assign object and pass vector to object
	Set sample2(vector2);

	// print set sample2
	cout << "\n\nshowing sample 2" << endl;
	sample2.Print();

	// make union of both sets
	Set sample3 = sample1.Union(sample2);

	// show out put of intersection
	cout << "\n\nshowing union of sample 1 and sample 2" << endl;
	sample3.Print();

	// make intersection of both sets
	Set sample4 = sample1.Intersection(sample2);
	// show out put of union
	cout << "\n\nshowing intersection of sample 1 and sample 2" << endl;
	sample4.Print();
	cout << endl;
}