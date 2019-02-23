/////////////////////////////////////////////////////////////////////////////////////
// Employee.h, The header file for the code contains functions and members         //
// the header Employee.h                                                           //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>					
#include<string>
#include "Point.h"                // include the header file
using namespace std;


//definition of class employee
class employee
{
public:
	//initilizing constructor
	employee(string, point&);
	void GetCoordinate(point &);
	void SetCoordinate(point &);
	void GetName(string &);
	void SetName(string &);
	
	//here we have the data members	
private:
	string name;
	point myPoint;
};

