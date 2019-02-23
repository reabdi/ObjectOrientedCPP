/////////////////////////////////////////////////////////////////////////////////////
// Set.cpp, The header file for the code contains functions and members            //
// the header Set.h                                                                //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<vector>								// directive for vector
#include<string>
#include "Set.h"
using namespace std;

//default constructor
Set::Set() :coordinate(vector<bool>(21, 0))
{
}

//parameter constructor
Set::Set(vector<bool> &v)
{
	coordinate = v;
}
// checking each element of vector
bool Set::IsMember(int position)
{
	bool g;
	g = (coordinate[position] == 1) ? 1 : 0;
	return g;
}
//getting union of two sets
Set Set::Union(Set &s)
{
	vector<bool>vectorSample(21, 0);
	for (int i = 0; i < 21; i++)
		vectorSample[i] = (s.IsMember(i) || IsMember(i));

	Set sample3(vectorSample);
	return sample3;
}
//getting intersection of twp sets
Set Set::Intersection(Set &s)
{
	vector<bool>vectorSample2(21, 0);
	for (int i = 0; i < 21; i++)
		vectorSample2[i] = (s.IsMember(i) && IsMember(i));

	Set sample4(vectorSample2);
	return sample4;
}
//showing out put of uion and intersection
void Set::Print()
{
	cout << "[ ";
	for (int i = 0; i < 21; i++)
	{
		cout << coordinate[i];
	}
	cout << " ]";
	cout << endl;
}
