/////////////////////////////////////////////////////////////////////////////////////
// MyCircle.cpp, The header file for the code contains functions and members       //
// the header MyCircle.h                                                           //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: December 04th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


#include "MyCircle.h"

using std::cout;
using std::cin;
using std::endl;



///////////////////////////////////////////////////////////////////////////////
// MyCircle default constructor
///////////////////////////////////////////////////////////////////////////////
MyCircle::MyCircle()
// initialize default circle attributes
: circleRadius(WINDOW_MAXY / 4)
{}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::Draw()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::Draw()
{
	// set up attributes of Circle using FilledShapes
	fs.SetPenColor(borderColor);
	fs.SetBrushColor(fillColor);

	// draw Circle with set attributes
	// We need to take into account the border width by subtracting the border
	// width appropriately from the length and width. 
	fs.FilledCircle(position, circleRadius - 2 * borderWidth);

	return true;
}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::SetRadius()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetRadius(unsigned int radius)
{
	// we need to account for a min length and width based
	// upon the border width
	if (radius <= 2 * borderWidth) return false;

	// check to make sure the new length is valid based on current position
	// window height, and window width 
	if (radius < (GetWindowHeight() - position.y) &&
		radius < (GetWindowWidth() - position.x))
	{
		circleRadius = radius;
		return true;
	}
	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::SetPosition()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetPosition(POINT & p)
{
	// we need to  make sure new position is valid based on current length, width,
	// and window size
	if ((p.x + circleRadius / 2 + borderWidth) < GetWindowWidth() &&
		(p.x > (circleRadius / 2 + borderWidth)) &&
		(p.y + circleRadius + borderWidth) < GetWindowHeight() &&
		(p.y > borderWidth)
		)
	{
		position.x = p.x;
		position.y = p.y;
		return true;
	}

	else
	{
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::GetRadius()
///////////////////////////////////////////////////////////////////////////////
unsigned int MyCircle::GetRadius()
{
	return circleRadius;
}
