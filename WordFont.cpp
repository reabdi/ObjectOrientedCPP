/////////////////////////////////////////////////////////////////////////////////////
// WordFont.cpp, The header file for the code contains functions and members       //
// the header WordFont.h                                                           //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: October 29th 2016                                                        //
/////////////////////////////////////////////////////////////////////////////////////

# include <iostream>
# include <vector>
# include <string>
# include "WordFont.h"
using namespace std;

//constructor initilizer
WordFont::WordFont() 
{
	int fontSize = 0;
	int bold = 0;
	char pixelCharacter = '*';
	string mainWord = "CAT";
}

void WordFont::askQuestion()
{
	// Asking the operator to enter the required inputs
	cout << "Enter a word (8 letters or less), using a, e, i, o, u, c, b, d, f, g, h, j, k, l, m, n, r, s, t, and z: " << endl;
	cin >> mainWord;				//The word which expected to be plotted
	cout << "Enter the prefered character you would like to use to draw: " << endl;
	cin >> pixelCharacter;			//the shape of character which is desired
	cout << "Enter the Font Size (8-12): " << endl;
	cin >> fontSize;				//font size of the each letter
	cout << "Bold? (0=No, 1=Yes) " << endl;
	cin >> boldForm;				//mentionenning that if the operator whant bold fomrmation or reqular
}


// almost the main method which will distinguish the characters and print them
void WordFont::wordPrinter()
{
	vector<vector<char>> wordList(fontSize, vector<char>(fontSize*mainWord.size() + mainWord.size() - 1));	//2D vector
	
	for (unsigned int i = 0; i < mainWord.size(); i++)
	{
		int position = i;						//Using the position, the code will locate the letter in correct location
		switch (mainWord[i])					//switch methodology for accessing private functions
		{
		case 'A':
		case 'a':
			printLetterA(wordList, fontSize, pixelCharacter, position, boldForm);
		break;
		case 'E':
		case 'e':
			printLetterE(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'I':
		case 'i':
			printLetterI(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'O':
		case 'o':
			printLetterO(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'U':
		case 'u':
			printLetterU(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'C':
		case 'c':
			printLetterC(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'B':
		case 'b':
			printLetterB(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'D':
		case 'd':
			printLetterD(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'F':
		case 'f':
			printLetterF(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'G':
		case 'g':
			printLetterG(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'H':
		case 'h':
			printLetterH(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'J':
		case 'j':
			printLetterJ(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'K':
		case 'k':
			printLetterK(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'L':
		case 'l':
			printLetterL(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'M':
		case 'm':
			printLetterM(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'N':
		case 'n':
			printLetterN(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'R':
		case 'r':
			printLetterR(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'S':
		case 's':
			printLetterS(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'T':
		case 't':
			printLetterT(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		case 'Z':
		case 'z':
			printLetterZ(wordList, fontSize, pixelCharacter, position, boldForm);
			break;
		default:cout << "The desired character is not in the list. Please re-enter the word";
			break;										              	// Default case
		}
	}
	// calling the printer function to print the word
	printer(wordList, fontSize, (fontSize*mainWord.size() + mainWord.size() - 1));
}

//the printer function
void WordFont::printer(vector<vector<char>> & wordList, int height, int width)
{
	for (int row = 0; row < height; row++) {
		// in this function height is the number of rows 
		for (int col = 0; col < width; col++) {
			// width is the column width that includes all the letter size and the void space between the letters
			cout << wordList[row][col];														// printing cell bcol cell
		}
		cout << "\n";																	// go to nerowt line
	}
}

//function for printing the letter A
void WordFont::printLetterA(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)					 wordList[row][col] = pixelCharacter;
				if (row == (fontSize / 2))		 wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize))) || (col == (fontSize + (blankSpace + position*fontSize)) - 1))
					wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))					 wordList[row][col] = pixelCharacter;
				if ((row == (fontSize / 2)) || (row == ((fontSize / 2) - 1)))		 wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (fontSize + (blankSpace + position*fontSize)) - 1)
					|| (col == (1 + (blankSpace + position*fontSize)))
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize)) - 1))
					wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for printing the letter E
void WordFont::printLetterE(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)               wordList[row][col] = pixelCharacter;
				if (row == (fontSize / 2))    wordList[row][col] = pixelCharacter;
				if (row == (fontSize - 1))        wordList[row][col] = pixelCharacter;
				if (col == (0 + (blankSpace + position*fontSize)))    wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))					 wordList[row][col] = pixelCharacter;
				if ((row == (fontSize / 2)) || (row == ((fontSize / 2) - 1)))		 wordList[row][col] = pixelCharacter;
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))		 wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize))))    wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for printing the letter I
void WordFont::printLetterI(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold) 
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)													wordList[row][col] = pixelCharacter;
				if (row == (fontSize - 1))										wordList[row][col] = pixelCharacter;
				if (col == (fontSize / 2) + blankSpace + position*fontSize)		wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))                                  wordList[row][col] = pixelCharacter;
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))		   wordList[row][col] = pixelCharacter;
				if ((col == (fontSize / 2) + blankSpace + position*fontSize)
					|| (col == (fontSize / 2) - 1 + blankSpace + position*fontSize))		wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for printing the letter O
void WordFont::printLetterO(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)
				{
					for (int i = (0 + (blankSpace + position*fontSize)); i < ((fontSize + (blankSpace + position*fontSize)) - 2); i++)
					{
						wordList[row][i + 1] = pixelCharacter;
					}
				}
				if (row == (fontSize - 1)) 
				{
					for (int i = (0 + (blankSpace + position*fontSize)); i < ((fontSize + (blankSpace + position*fontSize)) - 2); i++)
					{
						wordList[row][i + 1] = pixelCharacter;
					}
				}	
				if ((col == (0 + (blankSpace + position*fontSize))) || (col == (fontSize + (blankSpace + position*fontSize)) - 1))
				{
					for (int j = 0; j < (fontSize - 2); j++)
					{
						wordList[j + 1][col] = pixelCharacter;
					}
				}
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))
				{
					for (int i = (0 + (blankSpace + position*fontSize)); i < ((fontSize + (blankSpace + position*fontSize)) - 2); i++)
					{
						wordList[row][i + 1] = pixelCharacter;
					}
				}
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))
				{
					for (int i = (0 + (blankSpace + position*fontSize)); i < ((fontSize + (blankSpace + position*fontSize)) - 2); i++)
					{
						wordList[row][i + 1] = pixelCharacter;
					}
				}
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (fontSize + (blankSpace + position*fontSize)) - 1)
					|| (col == (1 + (blankSpace + position*fontSize)))
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize)) - 1))
				{
					for (int j = 0; j < (fontSize - 2); j++)
					{
						wordList[j + 1][col] = pixelCharacter;
					}
				}
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}


//function for printing the letter U
void WordFont::printLetterU(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == (fontSize - 1))      wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize))) || (col == (fontSize + (blankSpace + position*fontSize)) - 1))
					wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))		   wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (fontSize + (blankSpace + position*fontSize)) - 1)
					|| (col == (1 + (blankSpace + position*fontSize)))
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize)) - 1))
					wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for printing the letter C
void WordFont::printLetterC(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)               wordList[row][col] = pixelCharacter;
				if (row == (fontSize - 1))        wordList[row][col] = pixelCharacter;
				if (col == (0 + (blankSpace + position*fontSize)))    wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))					 wordList[row][col] = pixelCharacter;
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))		 wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize))))    wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for printing the letter B
void WordFont::printLetterB(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if ((row == 0) || (row == (fontSize / 2)) || (row == (fontSize - 1)))
					for (int i = 0; i < (fontSize - 1); i++)
					{
						wordList[row][(position*fontSize) + position + i] = pixelCharacter;
					}
				if (col == (0 + (blankSpace + position*fontSize))) 
					wordList[row][col] = pixelCharacter;
				if ((row == 0) && (col == (fontSize + (blankSpace + position*fontSize)) - 1))
					for (int i = 1; i < (fontSize / 2); i++)
					{
						wordList[i][col] = pixelCharacter;
					}
				if ((row == (fontSize / 2)) && (col == (fontSize + (blankSpace + position*fontSize)) - 1))
					for (int i = 1; i < ((fontSize / 2) - 1); i++)
					{
						wordList[(fontSize / 2) + i][col] = pixelCharacter;
					}
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1) || (row == (fontSize / 2)) || (row == ((fontSize / 2) - 1))		
					|| (row == (fontSize - 1)) || (row == (fontSize - 2)))		 
					for (int i = 0; i < (fontSize - 1); i++)
					{
						wordList[row][(position*fontSize) + position + i] = pixelCharacter;
					}
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize))))
					wordList[row][col] = pixelCharacter;
				if ((row == 0) && ((col == (fontSize + (blankSpace + position*fontSize)) - 1)
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize)) - 1)))
				{
					for (int i = 1; i < ((fontSize / 2 ) - 1); i++)
					{
						wordList[i][col] = pixelCharacter;
					}
				}
				if ((row == (fontSize / 2)) && ((col == (fontSize + (blankSpace + position*fontSize)) - 1)
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize)) - 1)))
				{
					for (int i = 1; i < ((fontSize / 2) - 1); i++)
					{
						wordList[(fontSize / 2) + i][col] = pixelCharacter;
					}
				}
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for printing the letter F
void WordFont::printLetterF(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)               wordList[row][col] = pixelCharacter;
				if (row == (fontSize / 2))    wordList[row][col] = pixelCharacter;
				if (col == (0 + (blankSpace + position*fontSize)))    wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))					 wordList[row][col] = pixelCharacter;
				if ((row == (fontSize / 2)) || (row == ((fontSize / 2) - 1)))		 wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize))))    wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for printing the letter D
void WordFont::printLetterD(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)
				{
					for (int i = (0 + (blankSpace + position*fontSize)); i < ((fontSize + (blankSpace + position*fontSize)) - 1); i++)
					{
						wordList[row][i] = pixelCharacter;
					}
				}
				if (row == (fontSize - 1))
				{
					for (int i = (0 + (blankSpace + position*fontSize)); i < ((fontSize + (blankSpace + position*fontSize)) - 1); i++)
					{
						wordList[row][i] = pixelCharacter;
					}
				}
				if (col == (0 + (blankSpace + position*fontSize)))            wordList[row][col] = pixelCharacter;
				if (col == (fontSize + (blankSpace + position*fontSize) - 1))
				{
					for (int j = 0; j < (fontSize - 2); j++)
					{
						wordList[j + 1][col] = pixelCharacter;
					}
				}
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))
				{
					for (int i = (0 + (blankSpace + position*fontSize)); i < ((fontSize + (blankSpace + position*fontSize)) - 1); i++)
					{
						wordList[row][i] = pixelCharacter;
					}
				}
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))
				{
					for (int i = (0 + (blankSpace + position*fontSize)); i < ((fontSize + (blankSpace + position*fontSize)) - 1); i++)
					{
						wordList[row][i] = pixelCharacter;
					}
				}
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize))))		 wordList[row][col] = pixelCharacter;

				if ((col == (fontSize + (blankSpace + position*fontSize) - 1))
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize)) - 1))
				{
					for (int j = 0; j < (fontSize - 2); j++)
					{
						wordList[j + 1][col] = pixelCharacter;
					}
				}
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for printing the letter G
void WordFont::printLetterG(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)               wordList[row][col] = pixelCharacter;
				if (row == (fontSize - 1))        wordList[row][col] = pixelCharacter;
				if (col == (0 + (blankSpace + position*fontSize)))
					wordList[row][col] = pixelCharacter;
				if (row == (fontSize / 2))
				{
					for (int j = 0; j < (fontSize / 2); j++)
					{
						wordList[fontSize / 2][(position*fontSize) + position + (fontSize / 2) + j] = pixelCharacter;
					}
				}
				if ((col == (fontSize + (blankSpace + position*fontSize) - 1)))
				{
					for (int j = 0; j < (fontSize / 2); j++)
					{
						wordList[(fontSize / 2) + j][col]  = pixelCharacter;
					}
				}
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))              wordList[row][col] = pixelCharacter;
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))        wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize))))
					wordList[row][col] = pixelCharacter;
				if (row == (fontSize / 2)) 
				{
					for (int j = 0; j < (fontSize / 2); j++)
					{
						wordList[fontSize / 2][(position*fontSize) + position + (fontSize / 2) + j] = pixelCharacter;
						wordList[(fontSize / 2) + 1][(position*fontSize) + position + (fontSize / 2) + j] = pixelCharacter;
					}
				}
				if ((col == (fontSize + (blankSpace + position*fontSize) - 1)))
				{
					for (int j = 0; j < (fontSize / 2); j++)
					{
						wordList[(fontSize / 2) + j][col] = pixelCharacter;
						wordList[(fontSize / 2) + j][col - 1] = pixelCharacter;
					}
				}
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for printing the letter H
void WordFont::printLetterH(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == (fontSize / 2))               wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize))) || (col == (fontSize + (blankSpace + position*fontSize)) - 1))
					wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == (fontSize / 2)) || (row == ((fontSize / 2) - 1)))	     wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize)))
					|| (col == (fontSize + (blankSpace + position*fontSize) - 1))
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize) - 1)))  
					wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}


//function for printing the letter J
void WordFont::printLetterJ(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == (fontSize - 1))               wordList[row][col] = pixelCharacter;
				if (col == (fontSize + (blankSpace + position*fontSize)) - 1)
					wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))	     wordList[row][col] = pixelCharacter;
				if ((col == (fontSize + (blankSpace + position*fontSize) - 1))
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize) - 1)))
					wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}


//function for printing the letter L
void WordFont::printLetterL(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == (fontSize - 1))        wordList[row][col] = pixelCharacter;
				if (col == (0 + (blankSpace + position*fontSize)))    wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))		 wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize))))    wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}


//function for printing the letter K
void WordFont::printLetterK(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (col == (0 + (blankSpace + position*fontSize)))
					wordList[row][col] = pixelCharacter;
				if (row == (fontSize / 2))
				{
					for (int i = 1; i < (fontSize / 2); i++)
						wordList[(fontSize / 2)][(position*fontSize) + position + i] = pixelCharacter;
				}
				if (row == 0)
				{
					for (int i = 0; i < (fontSize / 2); i++)
					{
						wordList[(fontSize / 2) + i][(position*fontSize) + (fontSize / 2) + position + i] = pixelCharacter;
					}
					for (int j = 0; j < (fontSize / 2); j++)
					{ 
						wordList[(fontSize / 2) - j - 1][(position*fontSize) + (fontSize / 2) + position + j] = pixelCharacter;
					}
				}
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize))))
					wordList[row][col] = pixelCharacter;
				if ((row == (fontSize / 2)) || (row == (fontSize / 2) - 1))
				{
					for (int i = 1; i < (fontSize / 2); i++)
						wordList[row][(position*fontSize) + position + i] = pixelCharacter;
				}
				if (row == 0)
				{
					for (int i = 0; i < (fontSize / 2); i++)
					{
						wordList[(fontSize / 2) + i][(position*fontSize) + (fontSize / 2) + position + i] = pixelCharacter;
						wordList[(fontSize / 2) + i - 1][(position*fontSize) + (fontSize / 2) + position + i] = pixelCharacter;
					}
					for (int j = 0; j < (fontSize / 2); j++)
					{
						wordList[(fontSize / 2) - j - 1][(position*fontSize) + (fontSize / 2) + position + j] = pixelCharacter;
						wordList[(fontSize / 2) - j][(position*fontSize) + (fontSize / 2) + position + j] = pixelCharacter;
					}
				}
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}


//function for printing the letter M
void WordFont::printLetterM(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if ((col == (0 + (blankSpace + position*fontSize))) || (col == (fontSize + (blankSpace + position*fontSize)) - 1))
					wordList[row][col] = pixelCharacter;
				if (row == 0)
				{
					for (int i = 1; i <= (fontSize / 2); i++)
					{
						wordList[row + i][(position*fontSize) + position + i] = pixelCharacter;
					}
					for (int j = 1; j <= (fontSize / 2); j++)
					{
						wordList[row + j][(position*fontSize) + position + fontSize - j] = pixelCharacter;
					}
				}
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize)))
					|| (col == (fontSize + (blankSpace + position*fontSize) - 1))
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize) - 1)))
					wordList[row][col] = pixelCharacter;
				if ((row == 0) || (row == 1))
				{
					for (int i = 1; i <= (fontSize / 2); i++)
					{
						wordList[row + i][(position*fontSize) + position + i] = pixelCharacter;
					}
					for (int j = 1; j <= (fontSize / 2); j++)
					{
						wordList[row + j - 1][(position*fontSize) + position + fontSize - j] = pixelCharacter;
					}
				}
			}
		}
	}
considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}


//function for printing the letter N
void WordFont::printLetterN(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if ((col == (0 + (blankSpace + position*fontSize))) || (col == (fontSize + (blankSpace + position*fontSize)) - 1))
					wordList[row][col] = pixelCharacter;
				if (row == 0)
				{
					for (int i = 1; i <= (fontSize - 1); i++)
					{
						wordList[row + i][(position*fontSize) + position + i] = pixelCharacter;
					}
				}
			}

			//for the bold condition
			if (bold == 1)
			{
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize)))
					|| (col == (fontSize + (blankSpace + position*fontSize) - 1))
					|| (col == (fontSize - 1 + (blankSpace + position*fontSize) - 1)))
					wordList[row][col] = pixelCharacter;
				if ((row == 0) || (row == 1))
				{
					for (int i = 1; i < (fontSize - 1); i++)
					{
						wordList[row + i][(position*fontSize) + position + i] = pixelCharacter;
					}
				}
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}



//function for printing the letter R
void WordFont::printLetterR(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)               wordList[row][col] = pixelCharacter;
				if (col == (0 + (blankSpace + position*fontSize)))
					wordList[row][col] = pixelCharacter;
				if (row == (fontSize / 2))
				{
					wordList[row][col] = pixelCharacter;
					for (int i = 1; i < (fontSize / 2); i++)
						wordList[row + i][(fontSize / 2) + (position*fontSize) + position + i] = pixelCharacter;
				}
				if ((col == (fontSize + (blankSpace + position*fontSize) - 1)))
				{
					for (int j = 0; j < (fontSize / 2); j++)
					{
						wordList[j][col] = pixelCharacter;
					}
				}
			}

		//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))               wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize)))
					|| (col == (1 + (blankSpace + position*fontSize))))
					wordList[row][col] = pixelCharacter;
				if (row == (fontSize / 2) || (row == ((fontSize / 2) - 1)))
				{
					wordList[row][col] = pixelCharacter;
					for (int i = 1; i < (fontSize / 2); i++)
						wordList[row + i][(fontSize / 2) + (position*fontSize) + position + i] = pixelCharacter;
				}
				if ((col == (fontSize + (blankSpace + position*fontSize) - 1))
					|| (col == (fontSize + (blankSpace + position*fontSize) - 2)))
				{
					for (int j = 0; j < (fontSize / 2); j++)
					{
						wordList[j][col] = pixelCharacter;
					}
				}
			}
		}	
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}



//function for printing the letter S
void WordFont::printLetterS(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if ((row == 0) || (row == (fontSize / 2)) || (row == (fontSize - 1)))      wordList[row][col] = pixelCharacter;
				if (col == (0 + (blankSpace + position*fontSize)))
				{
					for (int i = 1; i <= (fontSize / 2); i++)
					{
						wordList[i][col] = pixelCharacter;
					}
				}
				if (col == (fontSize + (blankSpace + position*fontSize) - 1))
				{
					for (int i = 0; i < (fontSize / 2); i++)
					{
						wordList[(fontSize / 2) + i][col] = pixelCharacter;
					}
				}
			}
			//for the bold condition
			{
				if ((row == 0) || (row == (fontSize / 2)) || (row == (fontSize - 1))
					|| (row == 1) || (row == (fontSize / 2) - 1) || (row == (fontSize - 2)))  
					wordList[row][col] = pixelCharacter;
				if ((col == (0 + (blankSpace + position*fontSize))) || (col == (1 + (blankSpace + position*fontSize))))
				{
					for (int i = 1; i <= (fontSize / 2); i++)
					{
						wordList[i][col] = pixelCharacter;
					}
				}
				if ((col == (fontSize - 1 + (blankSpace + position*fontSize))) || (col == (fontSize - 2 + (blankSpace + position*fontSize))))
				{
					for (int i = 0; i < (fontSize / 2); i++)
					{
						wordList[(fontSize / 2) + i][col] = pixelCharacter;
					}
				}
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}



//function for printing the letter T
void WordFont::printLetterT(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == 0)													wordList[row][col] = pixelCharacter;
				if (col == (fontSize / 2) + blankSpace + position*fontSize)		wordList[row][col] = pixelCharacter;
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == 0) || (row == 1))                                  wordList[row][col] = pixelCharacter;
				if ((col == (fontSize / 2) + blankSpace + position*fontSize)
					|| (col == (fontSize / 2) - 1 + blankSpace + position*fontSize))		wordList[row][col] = pixelCharacter;
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}


//function for printing the letter Z
void WordFont::printLetterZ(vector<vector<char>> & wordList, int fontSize, char pixelCharacter, int position, int bold)
{
	blankSpace = useBlankSpace();			// call the amount of blank space from private function
	for (int row = 0; row < fontSize; row++)
	{
		//columsn need to be adjusted for spacing and other letters
		for (int col = 0 + (blankSpace + position*fontSize); col < fontSize + (blankSpace + position*fontSize); col++)
		{
			//for regular condition -non bold-
			if (bold == 0)
			{
				if (row == (fontSize - 1))	wordList[row][col] = pixelCharacter;
				if (row == 0)
				{
					wordList[row][col] = pixelCharacter;
					int j = 1;
					for (int i = ((fontSize / 2) + (fontSize / 3)); i >= 1; i--)
					{
						wordList[row + j][(position*fontSize) + position + i] = pixelCharacter;
						j++;
					}
				}
			}
			//for the bold condition
			if (bold == 1)
			{
				if ((row == (fontSize - 1)) || (row == (fontSize - 2)))	wordList[row][col] = pixelCharacter;
				if ((row == 0) || (row == 1))
				{
					wordList[row][col] = pixelCharacter;
					int j = 0;
					for (int i = ((fontSize / 2) + (fontSize / 3)); i >= 1; i--)
					{
						wordList[row + j][(position*fontSize) + position + i] = pixelCharacter;
						j++;
					}
				}
			}
		}
	}
	considerBlankSpace();	//incrementing the numbr of blank space for nerowt rounds
}

//function for setting the blank space between the letters
void WordFont::considerBlankSpace()
{
	blankSpace = blankSpace + 1;
}

//function for using the white space at the beginning
int WordFont::useBlankSpace()
{
	return blankSpace;
}