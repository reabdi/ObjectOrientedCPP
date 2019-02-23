/////////////////////////////////////////////////////////////////////
// screensaver.cpp
// Author: Joe Waclawski
// Description: Simple screensaver to demonstrate MyRect class
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// MyTriangle.h, The header file for the code contains functions and members       //
// the header MyTriangle.h                                                         //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: December 04th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////

#include "MyRect.h"
#include "MyTriangle.h"
#include "MyCircle.h"
#include <stdlib.h> // rand and srand
#include <time.h> // time funciton
#include <windows.h>  // POINT object
#include <vector>
#include <map>

// how many times will the program cycle
#define PROGRAM_RUN 55

// small delay between drawing rectangles during each run
#define DRAW_DELAY 150

// small delay between each iteration of drawing rectangles
#define ITERATION_DELAY 400

#define NUM_SHAPES 1

// function prototypes
void RandomAttributes(MyRect &);
void RandomAttributes(MyTriangle &);
void RandomAttributes(MyCircle &);

void RandomAttributes(Shape *);
enum SHAPE_TYPES{ RECTANGLE = 10, TRIANGLE = 11, CIRCLE = 12 };
void main()
{
	int shapes=0; // loop index

	// seed the random number generator
	srand((unsigned int)time(0));

	// allow the user time to move the console window away
	// from the FilledShapes window are
	cout << "Move this window to the lower right of the screen, and press ENTER to continue:\n";
	cin.get();			// wait for user to press enter


	// declare a map with the shape type and value of shape of vectors
	map<SHAPE_TYPES, vector<Shape *>> shapeMap;	
	vector<Shape *> rectangleVector;
	vector<Shape *> triangleVector;				//declare vectors for each shape
	vector<Shape *> circleVector;


	//Insert the initial vectors to the map
	shapeMap.insert(pair<SHAPE_TYPES, vector<Shape *>>(RECTANGLE, rectangleVector));
	shapeMap.insert(pair<SHAPE_TYPES, vector<Shape *>>(TRIANGLE, triangleVector));
	shapeMap.insert(pair<SHAPE_TYPES, vector<Shape *>>(CIRCLE, circleVector));
	
	//map iterator to interate over the map
	map<SHAPE_TYPES, vector<Shape *>>::iterator mapIter;		

	for (int i = 0; i < PROGRAM_RUN; i++)
	{

		Shape *S = new MyRect();			// shape pointer points to new retangle object
		RandomAttributes(S);				// rectangle's attributes are set randomly
		mapIter = shapeMap.find(RECTANGLE);// find the rectangle with key
		if (mapIter != shapeMap.end())
		{
			// the key was found, so add data 
			mapIter->second.push_back(S);
		}

		
		Shape *S1 = new MyTriangle();
		RandomAttributes(S1);
		//Triangles attributes are set randomly
		mapIter = shapeMap.find(TRIANGLE);
		if (mapIter != shapeMap.end())
		{
			// the key was found, so add data 
			mapIter->second.push_back(S1);
		}

		Shape *S2 = new MyCircle();
		RandomAttributes(S2);
		// circles attributes are set randomly
		mapIter = shapeMap.find(CIRCLE);
		if (mapIter != shapeMap.end())
		{
			// the key was found, so add data 
			mapIter->second.push_back(S2);
		}

	}

	// Display the map
	for (int i = 0; i < PROGRAM_RUN; i++)
	{
		mapIter = shapeMap.find(RECTANGLE);
		if (mapIter != shapeMap.end())
		{
			if (!mapIter->second.empty())
			{
				mapIter->second.back()->ClearScreen();	// clear the screen of previous shapes
				mapIter->second.back()->Draw();

				delete mapIter->second.back();
				// delete the pointer once its used
				mapIter->second.pop_back();						// remove the displayed shape
			}
		}


		mapIter = shapeMap.find(TRIANGLE);
		if (mapIter != shapeMap.end())
		{
			if (!mapIter->second.empty())
			{
				mapIter->second.back()->Draw();	     	// draw the shape

				delete mapIter->second.back();	    	// deleting the pointer is important

				mapIter->second.pop_back();				// remove the displayed shape	
			}
		}

		mapIter = shapeMap.find(CIRCLE);
		if (mapIter != shapeMap.end())
		{
			if (!mapIter->second.empty())
			{
				
				mapIter->second.back()->Draw();		     // draw circle

				delete mapIter->second.back();

				mapIter->second.pop_back();			     // remove the displayed shape
			}
		}
		if (ITERATION_DELAY > 0)
			Sleep(ITERATION_DELAY);		            	// time duration between shapes

	}

}

/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a MyRect object, and draw it.
// 
// Inputs: MyRect object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////

void RandomAttributes(MyRect &S)
{
	// needed to draw a filled shape
	POINT p;
	p.x=50;
	p.y=50;

	// define variables that will hold he parameters
	// for the rectangle
	SHAPE_COLOR firstColor=RED;
	SHAPE_COLOR lastColor=PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;
	unsigned int width;

	// reset the rectangle object to some known, legal values
	S.SetPosition(p);
	S.SetLength(S.GetWindowHeight()/10);
	S.SetWidth(S.GetWindowWidth()/10);

	// generate random values for our parameters, within
	// allowable limits
	//RED = 1, PURPLE = 6: 1+rand()%6
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);		// come out of the loop once values are different

	// set up the parameters of the filled shape
	// object per the random data
	S.SetBorderColor((SHAPE_COLOR)myPen);
	S.SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a rectangle within the legal
	// limits of the window.

	// length
	do {
		length = 1 + rand() % S.GetWindowHeight();
	} while(!S.SetLength(length));			//loop till SetLength return false values 

	// width
	do {
		width = 1 + rand() % S.GetWindowWidth();
	} while(!S.SetWidth(width));

	// position
	do {
		p.x = 1 + rand() % S.GetWindowWidth();
		p.y = 1 + rand() % S.GetWindowHeight();
	} while(!S.SetPosition(p));
}

/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a MyTriangle object, and draw it.
// 
// Inputs: MyTriangle object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void RandomAttributes(MyTriangle &S)
{
	// needed to draw a filled shape
	POINT p;
	p.x=50;
	p.y=50;

	// define variables that will hold he parameters
	// for the rectangle
	SHAPE_COLOR firstColor=RED;
	SHAPE_COLOR lastColor=PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;

	// reset the rectangle object to some known, legal values
	S.SetPosition(p);
	S.SetLength(S.GetWindowHeight()/10);

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	S.SetBorderColor((SHAPE_COLOR)myPen);
	S.SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a rectangle within the legal
	// limits of the window.

	// length
	do {
		length = 1 + rand() % S.GetWindowHeight();
	} while(!S.SetLength(length));

	// position
	do {
		p.x = 1 + rand() % S.GetWindowWidth();
		p.y = 1 + rand() % S.GetWindowHeight();
	} while(!S.SetPosition(p));
}




void RandomAttributes(MyCircle &S)
{
	// needed to draw a filled shape
	POINT p;
	p.x = 50;
	p.y = 50;

	// define variables that will hold he parameters
	// for the rectangle
	SHAPE_COLOR firstColor = RED;
	SHAPE_COLOR lastColor = PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int radius;


	// reset the Circle object to some known, legal values
	S.SetPosition(p);
	S.SetRadius(S.GetWindowHeight() / 10);

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	S.SetBorderColor((SHAPE_COLOR)myPen);
	S.SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a Circle within the legal
	// limits of the window.

	// radius
	do {
		radius = 1 + rand() % S.GetWindowWidth();
	} while (!S.SetRadius(radius));

	// position
	do {
		p.x = 1 + rand() % S.GetWindowWidth();
		p.y = 1 + rand() % S.GetWindowHeight();
	} while (!S.SetPosition(p));
}


//----< generic random attributes function------>
void RandomAttributes(Shape *S)
{
	MyRect *rect = dynamic_cast<MyRect *> (S);		// downcasting is used
	MyTriangle *tri = dynamic_cast<MyTriangle *> (S);	
	MyCircle *circ = dynamic_cast<MyCircle *>(S);

	if (rect != 0)		
	{
		RandomAttributes(*rect);
	}

	if (tri != 0)			// if downcasting was successful then random attributes is called
	{
		RandomAttributes(*tri);
	}

	if (circ != 0)
	{
		RandomAttributes(*circ);
	}

}
