/////////////////////////////////////////////////////////////////////////////////////
// Employee.cpp, The header file for the code contains functions and members       //
// the header Employee.h                                                           //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<vector>					
#include<string>
#include "Employee.h"                // include the header file
#include "Point.h" 
using namespace std;


//default and parametr constructor
employee::employee(string name1, point &p)
	:myPoint(p)
{
	name = name1;
}

// functions defination
void employee::GetCoordinate(point &p)
{
	p.SetX(myPoint.GetX());
	p.SetY(myPoint.GetY());
}
void employee::SetCoordinate(point &p)
{
	myPoint.SetX(p.GetX());
	myPoint.SetY(p.GetY());
}
// to receive name of employee
void employee::GetName(string &name1)
{
	name1 = name;
}
//to set employee's name
void employee::SetName(string &name1)
{
	name = name1;
}
