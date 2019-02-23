///////////////////////////////////////////////////////////////////////////
// Source.cpp, contains the object "myCAI" from CAI class		         //
// the header file CAI.h                                                 //
// Course Name: Object Oriented Programming CIS-554                      //
// Author: Reza ABdi, Syracuse University, MSCE                          //
//         email: reabdi@syr.edu, SUID: reabdi                           //
// Build: October 4th 2016                                               //
///////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <string>
#include "CAI.h"
using namespace std;

int main()
{
	CAI myCAI(0);					//creating the object of the class titled "myCAI"
	myCAI.askRandomQuestions();		//calling the function to launch the code and call the other functions
}