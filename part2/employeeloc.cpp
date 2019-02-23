/////////////////////////////////////////////////////////////////////////////////////
// EmployeeLoc.cpp, The header file for the code contains functions and members    //
//                                                                                 //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>	
#include<string>
#include "point.h"
#include "employee.h"
#include "location.h"
using namespace std;

void main()
{
	//initilization of x,y and name of person
	int xCoordinate, yCoordinate;

	string name;
	string city;

	//to get name of employee
	cout << "Enter Employees Name: ";
	cin >> name;
	//to get x and y of location
	cout << "\nEnter Position X (-1 to quite): ";
	cin >> xCoordinate;

	cout << "\nEnter Position Y (-1 to quite): ";
	cin >> yCoordinate;
	cout << endl;

	// applying the x and y coordinates and the created clases as objects to locate the employee
	while (xCoordinate != EOF && yCoordinate != EOF) 
	{
		point myPoint(xCoordinate, yCoordinate);

		employee myEmployee(name, myPoint);
		location myLocation;
		point myPoint_2;

		myEmployee.GetCoordinate(myPoint_2);
		location::LOCATION place = myLocation.GetLocation(myPoint_2);

		// to convert number of enumaration to name of cities
		switch (place) 
		{
		case 0:
			city = "NOT_FOUND";
			break;
		case 1:
			city = "NEWYORK";
			break;
		case 2:
			city = "SANFRANSISCO";
			break;
		case 3:
			city = "LOSANGELES";
			break;
		case 4:
			city = "CHICAGO";
			break;
		}
		cout << name << " is in " << city << endl;
		return;
	}
}