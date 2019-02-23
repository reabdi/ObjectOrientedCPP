///////////////////////////////////////////////////////////////////////////
// CAI.cpp, contains the definition for all the methods declared in      //
// the header file CAI.h                                                 //
// Course Name: Object Oriented Programming CIS-554                      //
// Author: Reza ABdi, Syracuse University, MSCE                          //
//         email: reabdi@syr.edu, SUID: reabdi                           //
// Build: October 4th 2016                                               //
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CAI.h"	//The header file is included
using namespace std;

//Constructor containing the initial values for private variables
CAI::CAI(int)
{
	multiCorrect = 0;
	multiIncorrect = 0;
	multi1 = 0;
	multi2 = 0;
	divissionCorrect = 0;
	divissionIncorrect = 0;
	divission1 = 0;
	divission2 = 0;
}

//The main method in the code which calls other methods
void CAI::askRandomQuestions()
{
	cout << "Welcome to the elementary school CAI program." << endl;
	cout << "Lets start with 5 multiplication question!" << endl;
	srand(time(0));														//to get different random values, called once above all
	cout << "*******************************************\n" << endl;	//For loop for asking 5 questions
	for (int counter = 1; counter <= 5; counter++)
	{
		multiCalculator();												//Calling another function for asking the question
	}
	cout << "*******************************************\n" << endl;		
	cout << "Now get ready for 5 devision questions!" << endl;			
	for (int counter = 1; counter <= 5; counter++)						//Second loop for asking the next set of the questions
	{
		divisionCalculator();											//Calling the relevant method to ask divission questions
	}
	cout << "*******************************************\n" << endl;

	printTheSummary();													//Calling the printer function to add summary at the end of the results
}

//This function would ask multiplication questions
void CAI::askRandomMultiplication()
{
	cout << "How much is " << multi1 << " times " << multi2 << endl;

}

//This function would ask the divission questions
void CAI::askRandomDivission()
{
	cout << "How much is " << divission1 << " divided by " << divission2 << endl;
}

//The function which prints good job comments randomly
void CAI::printRandomGoodJob()
{
	int goodJob;
	goodJob = 1 + rand() % 4;							//Using rand command to create random numbers
	switch (goodJob)									//Switch statement for making connection between the random numbers and comments.
	{
	case 1:
		cout << "Very Good!" << endl;
		break;
	case 2:
		cout << "Excellent!" << endl;
		break;
	case 3:
		cout << "Nice Work!" << endl;
		break;
	case 4:
		cout << "Keep Up The Good Work!" << endl;
		break;
	}
}

//The function print the comments when the answer is wrong, again randomly
void CAI::printRandomEncouragement()
{
	int Encouragement;
	Encouragement = 1 + rand() % 4;						//Using rand command to create random numbers
	switch (Encouragement)								//Switch statement for making connection between the random numbers and comments.
	{
	case 1:
		cout << "No, Please try again!" << endl;
		break;
	case 2:
		cout << "Wrong, Try once more!" << endl;
		break;
	case 3:
		cout << "Don't give up!" << endl;
		break;
	case 4:
		cout << "No, keep trying!" << endl;
		break;
	}
}

//This function specifically is for choosing random numbers
int CAI::chooseRandomNumber()
{
	int random;
	random = 1 + rand() % 9;				//the numbers are between 1 through 9
	return random;
}

//The function for calculating the multiplication questions
void CAI::multiCalculator()
{
	int multi;
	int multiAnswer;
	int multiFlag = 0;
	multi1 = chooseRandomNumber();			//Creating the first random number
	multi2 = chooseRandomNumber();			//Creating the second random number
	askRandomMultiplication();				//Calling the method to ask the question using the numbers which have created
	cout << "Enter your answer" << endl;	
	cin >> multiAnswer;						//Getting the answer
	multi = multi1 * multi2;				//The correct answer
	if (multi == multiAnswer)				//Creating an if statement to compare the answer w/ the correct one
		multiCorrect++;						//Counting the answers which are correct in the first try
	while (multiFlag != 1)					//While loop and a flag to check the answers
	{
		if (multi != multiAnswer)			//If the answer is incorrect
		{	
			multiFlag = 0;
			printRandomEncouragement();		//Calling another method to print the wrong-answer comment
			multiIncorrect++;				//Counting the wrong answers
			askRandomMultiplication();		//Calling the method to ask again
			cout << "Enter your answer" << endl;
			cin >> multiAnswer;				
		}
		else
		{
			multiFlag = 1;
			printRandomGoodJob();			//If the answer is correct, then the code will call the relevant method for a good job comment
		}
	}
	multiFlag = 0;							//Setting the flag to zero for the next question
}

void CAI::divisionCalculator()
{
	int division;
	int divissionAnswer;
	int divissionFlag = 0;
	divission1 = chooseRandomNumber();				//Creating the first random number
	divission2 = chooseRandomNumber();				//Creating the second random number
	askRandomDivission();							//Calling the method to ask the question using the numbers which have created
	cout << "Enter your answer" << endl;
	cin >> divissionAnswer;							//Getting the answer
	division = divission1 / divission2;				//The correct answer
	if (division == divissionAnswer)				//Creating an if statement to compare the answer w/ the correct one
		divissionCorrect++;							//Counting the answers which are correct in the first try
	while (divissionFlag != 1)						//While loop and a flag to check the answers
	{
		if (division != divissionAnswer)			//If the answer is incorrect
		{
			divissionFlag = 0;						//Setting the flag to zero
			printRandomEncouragement();				//Calling another method to print the wrong-answer comment
			divissionIncorrect++;					//Counting the wrong answers
			askRandomDivission();					//Calling the method to ask again
			cout << "Enter your answer" << endl;
			cin >> divissionAnswer;
		}
		else
		{
			divissionFlag = 1;				
			printRandomGoodJob();					//If the answer is correct, then the code will call the relevant method for a good job comment
		}
	}
	divissionFlag = 0;								//Setting the flag to zero for the next question
}

//This function prints the summary of the answers at the end of the calculations
void CAI::printTheSummary()
{
	int firstCorrect = multiCorrect + divissionCorrect;					//Calculating the number of first answers in the first try
	int firistIncorrect = 10 - firstCorrect;							//The number of rest of the questions
	int incorrectNumber = multiIncorrect + divissionIncorrect;			//Calculating the average number of wrong answers for each wrong questions
	cout << "Summary" << endl;
	cout << "First trial correct : " << firstCorrect << endl;
	cout << "First trial incorrect : " << firistIncorrect << endl;
	cout << "Average number of wrong answer for the whole test is: " << incorrectNumber / firistIncorrect << endl;
}