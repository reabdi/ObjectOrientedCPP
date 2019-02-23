
/////////////////////////////////////////////////////////////////////////////////////
// HugeInt.h, The header file for the code contains functions and members          //
// the header HugeInt.h                                                            //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: November 27th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
	friend ostream &operator<<(ostream &, const HugeInt &);	//operator overloading for output stream

public:
	static const int digits = 30; // maximum digits in a HugeInt

	HugeInt(long = 0, char = '+');			 // conversion/default constructor that accepts long parameter
	HugeInt(const string &, char = '+');	 // conversion constructor that accepts reference to constant string
	
	//=============================================================//
	// addition operator; HugeInt + HugeInt
	HugeInt operator+(const HugeInt &) const;

	// addition operator; HugeInt + int
	HugeInt operator+(int) const;

	// addition operator; 
	// HugeInt + string that represents large integer value
	HugeInt operator+(const string &) const;

	//=============================================================//
	// subtraction operator; HugeInt - HugeInt
	HugeInt operator-(const HugeInt &) const;

	//subtraction operator; HugeInt - int
	HugeInt operator-(int) const;

	// subtraction operator; 
	// HugeInt - string that represents large integer value
	HugeInt operator-(const string &) const;

	//=============================================================//
	// Multiplication operator; HugeInt * HugeInt
	HugeInt operator*(const HugeInt &) const;

	// Multiplication operator; HugeInt * int
	HugeInt operator*(int) const;

	// multiplication operator; 
	// HugeInt * string that represents large integer value
	HugeInt operator*(const string &) const;

	//=============================================================//
	// Division operator; HugeInt / HugeInt
	HugeInt operator/(const HugeInt &) const;

	// Division operator; HugeInt / int
	HugeInt operator/(int) const;

	// Division operator; 
	// HugeInt / string that represents large integer value
	HugeInt operator/(const string &) const;

	//=============================================================//
	// Equality operator; HugeInt == HugeInt
	bool operator==(const HugeInt &) const;

	// Equality operator; HugeInt == int
	bool operator==(int) const;

	// Equality operator; 
	// HugeInt == string that represents large integer value
	bool operator==(const string &) const;

	//=============================================================//
	// Inequality operator; HugeInt != HugeInt
	bool operator!=(const HugeInt &) const;

	// Inequality operator; HugeInt != int
	bool operator!=(int) const;

	// Ineuality operator; 
	// HugeInt != string that represents large integer value
	bool operator!=(const string &) const;

	//=============================================================//
	// Less than operator; HugeInt < HugeInt
	bool operator<(const HugeInt &) const;

	// Less than operator; HugeInt < int
	bool operator<(int) const;

	// Less than operator; 
	// HugeInt < string that represents large integer value
	bool operator<(const string &) const;

	//=============================================================//
	// Greater than operator; HugeInt > HugeInt
	bool operator>(const HugeInt &) const;

	// Greater than operator; HugeInt > int
	bool operator>(int) const;

	// Greater than operator; 
	// HugeInt > string that represents large integer value
	bool operator>(const string &) const;

	//=============================================================//
	// Less than or equal to operator; HugeInt <= HugeInt
	bool operator<=(const HugeInt &) const;

	// Less than or equal to operator; HugeInt <= int
	bool operator<=(int) const;

	// Less than or equal to operator; 
	// HugeInt <= string that represents large integer value
	bool operator<=(const string &) const;

	//=============================================================//
	// Greater than or equal to operator; HugeInt <= HugeInt
	bool operator>=(const HugeInt &) const;

	// Greater than or equal to operator; HugeInt <= Int
	bool operator>=(int) const;

	// Greater than or equal to operator; 
	// HugeInt <= string that represents large integer value
	bool operator>=(const string &) const;

	//=============================================================//
private:
	char sign = '+';				// character that contains number sign
	short integer[digits];			// array that has numbers
}; // end class HugeInt

#endif


/**************************************************************************
 * (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
