///////////////////////////////////////////////////////////////////////////
// CAI.h, The header file for the code contains functions and members    //
// the header file CAI.h                                                 //
// Course Name: Object Oriented Programming CIS-554                      //
// Author: Reza ABdi, Syracuse University, MSCE                          //
//         email: reabdi@syr.edu, SUID: reabdi                           //
// Build: October 4th 2016                                               //
///////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

// Class defination
class CAI
{
public:										//Public fucntions
	CAI(int);								//The constructor including the private values
	void askRandomQuestions();				//The main method in the code which calls other methods 
	void askRandomMultiplication();			//This function would ask multiplication questions
	void askRandomDivission();				//This function would ask the divission questions
private:									//Private section
	void printRandomGoodJob();				//The function which prints good job comments randomly
	void printRandomEncouragement();		//The function print the comments when the answer is wrong, again randomly
	void multiCalculator();					//The function for calculating the multiplication questions
	void divisionCalculator();				//The function for calculating the divission questions
	int chooseRandomNumber();				//This function specifically is for choosing random numbers
	void printTheSummary();					//This function prints the summary of the answers at the end of the calculations
	int multiCorrect;						//Required private variables for multiplications 
	int multiIncorrect;
	int multi1;
	int multi2;
	int divissionCorrect;					//Required private variables for divission
	int divissionIncorrect;
	int divission1;
	int divission2;
};