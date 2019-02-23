/////////////////////////////////////////////////////////////////////////////////////
// MyCircle.h, The header file for the code contains functions and members         //
// the header MyCircle.h                                                           //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: December 04th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////

#ifndef __MY_CIRCLE__
#define __MY_CIRCLE__

// include appropriate prototypes
#include "FilledShapes.h"
#include "Shape.h"
#include <windows.h>

class MyCircle : public Shape {

public:
	///////////////////////////////////////////////////////////////////////////////
	// Function: Default Constructor
	// Purpose: Construct a Circle.
	//
	// Inputs: None
	// Outputs: None
	// 
	// Returns: None
	///////////////////////////////////////////////////////////////////////////////
	MyCircle();

	///////////////////////////////////////////////////////////////////////////////
	// Function: Draw
	// Purpose: Draw the triangle with the current attributes
	//
	// Inputs: None
	// Outputs: None
	// 
	// Returns: true if successful, false otherwise
	///////////////////////////////////////////////////////////////////////////////
	virtual bool Draw();


	///////////////////////////////////////////////////////////////////////////////
	// Function: SetRadius
	// Purpose: Set the Radius of the circle (i.e. in the y direction)
	//
	// Inputs: int Radius - desired radius of circle
	// Outputs: None
	// 
	// Returns: true if successful, false otherwise
	///////////////////////////////////////////////////////////////////////////////
	bool SetRadius(unsigned int radius);

	///////////////////////////////////////////////////////////////////////////////
	// Function: GetRadius
	// Purpose: Get the Radius of the circle (i.e. in the y direction)
	//
	// Inputs: None
	// Outputs: None
	// 
	// Returns: current radius of circle
	///////////////////////////////////////////////////////////////////////////////
	unsigned int GetRadius();

	///////////////////////////////////////////////////////////////////////////////
	// Function: SetPosition
	// Purpose: Set the position of the circle. This specifies an x,y coordinate
	//          of the upper left of the circle, inside the border.
	//
	// Inputs: POINT point - x,y coordinates 
	// Outputs: None
	// 
	// Returns: true if successful, false otherwise
	///////////////////////////////////////////////////////////////////////////////
	virtual bool SetPosition(POINT &point);

	// Private Stuff

private:

	unsigned int circleRadius;

}; // end class MyCircle declaration

#endif __MY_CIRCLE__