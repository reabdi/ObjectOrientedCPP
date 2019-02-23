/////////////////////////////////////////////////////////////////////////////////////
// WordFont.h, The header file for the code contains functions and members         //
// the header WordFont.h                                                           //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: October 29th 2016                                                        //
/////////////////////////////////////////////////////////////////////////////////////

# include <iostream>
# include <vector>
# include <string>
using namespace std;

class WordFont
{
public:
	WordFont();												//constructor
	void wordPrinter();										//the main function which holds the private functions
	void askQuestion();

private:
	int blankSpace = 0;													//private variable for making space between letters
	string mainWord;													//creating the required variables for the first step
	char pixelCharacter;
	int fontSize = 0;
	int boldForm = 0;
	void printLetterA(vector<vector<char>> &, int, char, int, int);		//private methods for all the desired letters
	void printLetterE(vector<vector<char>> &, int, char, int, int);
	void printLetterI(vector<vector<char>> &, int, char, int, int);
	void printLetterO(vector<vector<char>> &, int, char, int, int);
	void printLetterU(vector<vector<char>> &, int, char, int, int);
	void printLetterC(vector<vector<char>> &, int, char, int, int);
	void printLetterB(vector<vector<char>> &, int, char, int, int);
	void printLetterD(vector<vector<char>> &, int, char, int, int);
	void printLetterF(vector<vector<char>> &, int, char, int, int);
	void printLetterG(vector<vector<char>> &, int, char, int, int);
	void printLetterH(vector<vector<char>> &, int, char, int, int);
	void printLetterJ(vector<vector<char>> &, int, char, int, int);
	void printLetterK(vector<vector<char>> &, int, char, int, int);
	void printLetterL(vector<vector<char>> &, int, char, int, int);
	void printLetterM(vector<vector<char>> &, int, char, int, int);
	void printLetterN(vector<vector<char>> &, int, char, int, int);
	void printLetterR(vector<vector<char>> &, int, char, int, int);
	void printLetterS(vector<vector<char>> &, int, char, int, int);
	void printLetterT(vector<vector<char>> &, int, char, int, int);
	void printLetterZ(vector<vector<char>> &, int, char, int, int);
	void considerBlankSpace();								//the function will consider blank space between the letters
	int useBlankSpace();									//the function will be used in the calculation of columns
	void printer(vector<vector<char>> &, int, int);			//print function for printing the words
};

