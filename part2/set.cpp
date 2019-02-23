/////////////////////////////////////////////////////////////////////////////////////
// set.cpp, The header file for the code contains functions and members            //
// the header set.h                                                                //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<vector>								// directive for vector
#include<string>
#include "set.h"
using namespace std;

//default constructor
set::set() :coordinate(vector<bool>(21, 0))
{
}

//parameter constructor
set::set(vector<bool> &v)
{
	coordinate = v;
}
// checking each element of vector
bool set::IsMember(int position)
{
	bool g;
	g = (coordinate[position] == 1) ? 1 : 0;
	return g;
}
//getting union of two sets
set set::Union(set &s)
{
	vector<bool>vectorSample(21, 0);
	for (int i = 0; i < 21; i++)
		vectorSample[i] = (s.IsMember(i) || IsMember(i));

	set sample3(vectorSample);
	return sample3;
}
//getting intersection of twp sets
set set::Intersection(set &s)
{
	vector<bool>vectorSample2(21, 0);
	for (int i = 0; i < 21; i++)
		vectorSample2[i] = (s.IsMember(i) && IsMember(i));

	set sample4(vectorSample2);
	return sample4;
}
//showing out put of uion and intersection
void set::Print()
{
	cout << "[ ";
	for (int i = 0; i < 21; i++)
	{
		cout << coordinate[i];
	}
	cout << " ]";
	cout << endl;
}