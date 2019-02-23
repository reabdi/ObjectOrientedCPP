/////////////////////////////////////////////////////////////////////////////////////
// Source.cpp, The header file for the code contains functions and members         //
// the header WordFont.h                                                           //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: October 29th 2016                                                        //
/////////////////////////////////////////////////////////////////////////////////////

# include <iostream>
# include <vector>
# include <string>
# include "WordFont.h"
using namespace std;

void main() 
{
	WordFont myWordFont;				//definning object myWordFont
	myWordFont.askQuestion();			//function for asking the quastions
	myWordFont.wordPrinter();			// call the public function which handles each letter of the word
}