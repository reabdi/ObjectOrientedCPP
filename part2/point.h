/////////////////////////////////////////////////////////////////////////////////////
// Point.h, The header file for the code contains functions and members            //
// the header Point.h                                                              //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: November 13th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


#ifndef POINT_H
#define POINT_H

# include <iostream>
# include <vector>
# include <string>

class point 
{
public:
	point();			//constructor
	point(int, int);
	void SetY(int);		//getting and setting the coordinates
	void SetX(int);
	int GetY();
	int GetX();

	// and here we have the data members
private:

	int x;
	int y;
};

#endif
