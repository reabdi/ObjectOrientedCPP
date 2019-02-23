
/////////////////////////////////////////////////////////////////////////////////////
// HugeInt.cpp, The header file for the code contains functions and members        //
// the header HugeInt.h                                                            //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: November 27th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


// Exercise 11.9 Solution: Hugeint.cpp
// HugeInt member-function and friend-function definitions.
#include <iostream>
#include <stdexcept>
#include <cctype> // isdigit function prototype
#include "Hugeint.h" // HugeInt class definition
using namespace std;

//=============================================================//
// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt(long value, char newSign)
{
	sign = newSign;
	// initialize array to zero
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;

	// place digits of argument into array
	for (int j = digits - 1; value != 0 && j >= 0; --j)
	{
		integer[j] = value % 10;
		value /= 10;
	} // end for
} // end HugeInt default/conversion constructor

  // conversion constructor that converts a character string
  // representing a large integer into a HugeInt object
HugeInt::HugeInt(const string &number, char newSign)
{
	// initialize array to zero
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;

	// place digits of argument into array
	int length = number.size();

	if (length >= digits)
	{
		cout << "The length is greater than the limit" << endl;
	}
	else
	{
		for (int j = digits - length, k = 0; j < digits; ++j, ++k)
			if (isdigit(number[k]))
				integer[j] = number[k] - '0';		// To convert from char to int
													
	}
} // end HugeInt conversion constructor

//=========================== overloading "+" operator ==================================//
// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+(const HugeInt &op2) const
{
	HugeInt temp; // temporary result
	int carry = 0;

	for (int i = digits - 1; i >= 0; --i)
	{
		temp.integer[i] = integer[i] + op2.integer[i] + carry;

		// determine whether to carry a 1
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10;  // reduce to 0-9
			carry = 1;
		} // end if
		else // no carry
			carry = 0;
	} // end for

	return temp; // return copy of temporary object
} // end function operator+


//====================================================

// addition operator; HugeInt + int
HugeInt HugeInt::operator+(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator+ for two HugeInt objects
	return *this + HugeInt(op2);
} // end function operator+

//====================================================

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator+ for two HugeInt objects
	return *this + HugeInt(op2);
} // end function operator+


//=========================== overloading "-" operator ==================================//

HugeInt HugeInt::operator-(const HugeInt &op2) const
{
	HugeInt temp; // temporary result
	HugeInt num1 = *this;
	HugeInt num2 = op2;

	int m = 0, carry = 0, k = 0;
	int flag1 = 0, flag2 = 0;
	int sub1 = 0, sub2 = 0, tempSub = 0;
	int firstNumPos = 0, x = 0;
	int secondNumPos = 0, y = 0;

	//get the posistions of left most digit of both numbers
	for (x = 0; x < HugeInt::digits && (integer[x] == 0); ++x)
		; // skip leading zeros
	for (y = 0; y< HugeInt::digits && (op2.integer[y] == 0); ++y)
		; // skip leading zeros
	firstNumPos = x;
	secondNumPos = y;

	// if both numbers are positive do normal subtraction
	if ((num1.sign == '+' && num2.sign == '+'))
	{
		for (int i = digits - 1; i >= 0; --i)
		{
			if (integer[i] < op2.integer[i])		// if minuend is less than subtrahend	
			{
				flag1 = 1;
				sub1 = integer[i];
				sub1 += 10;						//borrowing one
				sub2 = op2.integer[i];
				temp.integer[i] = (sub1 - sub2) - carry;		//subtract after adding borrow
				carry = 1;
			}
			else
			{
				sub1 = integer[i];
				sub2 = op2.integer[i];
				temp.integer[i] = (sub1 - sub2) - carry;	// do normal subtraction 
				carry = 0;
			}
		}
		temp.sign = '+';		// output will be positive number
		return temp;
	}

	// 
	else if (((num1.sign == '-' && num2.sign == '+')))
	{
		num1.sign = '+';			// first make both numbers positive	
		num2.sign = '+';
		temp = num1 - num2;			// call te subtraction operator
		temp.sign = '-';			// make the output negative
		return temp;
	}
	else if (num1.sign == '+' && num2.sign == '-')
	{
		num1.sign == '+';
		num2.sign == '+';
		temp = num1 + num2;
		temp.sign = '+';			// output will be positive as -(-) will be +
		return temp;
	}
	else if (sign == '-' && op2.sign == '-')
	{
		num1.sign == '+';
		num2.sign == '+';
		temp = num1 + num2;			// do addition as both numbers will be negative
		temp.sign = '-';			// output will be negative
		return temp;
	}
	else
	{
		return temp;
	}

}

//====================================================

HugeInt HugeInt :: operator-(int op2) const
{
	return *this - HugeInt(op2);			// call - operator after converting int to object
}


//====================================================
HugeInt HugeInt :: operator-(const string &op2) const
{
	return *this - HugeInt(op2);		  // call - operator after converting string to object
}


//=========================== overloading "*" operator ==================================//

HugeInt HugeInt :: operator*(const HugeInt &op2) const
{
	HugeInt temp; // temporary result
	int carry = 0, mulTemp = 0, mulCount = 0;		// initialize variables to 0

	int tempArray1[digits], tempArray2[digits];
	for (int l = 0; l < digits; l++) tempArray1[l] = 0; // initialize array to 0


	for (int i = digits - 1; i >= 0; i--)	// first loop for second arrays first number
	{
		carry = 0;
		// second loop to iterate over first arrays numbers
		for (int j = digits - 1; j - mulCount >= 0; j--)
		{
			//<-- if product is greater than 10 get the remainder 
			// and add carry to next number
			if (op2.integer[j] * integer[i] >= 10)
			{
				mulTemp = integer[i] * op2.integer[j];
				tempArray1[j - mulCount] += (mulTemp % 10) + carry;
				carry = mulTemp / 10;
			}
			else
			{
				// add previous carry if there 
				// otherwise there is no carry
				mulTemp = op2.integer[j] * integer[i];
				tempArray1[j - mulCount] += mulTemp + carry;
				carry = 0;
			}
		}

		mulCount++; // keep track of the position of rightmost number
					
	}

	for (int k = digits - 1; k >= 0; k--)  temp.integer[k] = tempArray1[k];

	if (sign == '-' || op2.sign == '-')	// if either numbers are negative make the output negative
	{
		temp.sign = '-';
	}

	return temp;
}


//====================================================
HugeInt HugeInt :: operator*(int op2) const
{
	return *this * HugeInt(op2);		// call * operator after converting int to object
}


//====================================================
HugeInt HugeInt :: operator*(const string &op2) const
{
	return *this * HugeInt(op2);		// call * operator after converting string to object
}


//=========================== overloading "/" operator ==================================//

HugeInt HugeInt :: operator/(const HugeInt &op2) const
{
	HugeInt quotient;
	HugeInt firstMul = *this;		// copy both objects 
	HugeInt secondMul = op2;

	if (((firstMul.sign == '+') && (secondMul.sign == '+')) || ((firstMul.sign == '-') && (secondMul.sign == '-')))
		//---< output will be positibe if both numbers are negative>------//
	{
		firstMul.sign = '+';
		secondMul.sign = '+';
		while (firstMul >= secondMul)
		{
			firstMul = firstMul - secondMul;
			quotient = quotient + 1;		// count how many times it takes for divider to be equal to 
											// or less than dividend
		}
		quotient.sign = '+';		// positive product
		return quotient;
	}
	else if (((firstMul.sign == '-') && (secondMul.sign == '+')) || ((firstMul.sign == '+') && (secondMul.sign == '-')))
	{
		firstMul.sign = '+';
		secondMul.sign = '+';
		quotient = firstMul / secondMul;
		quotient.sign = '-';			// negative output if one of them is negative
		return quotient;				// return the quotient
	}


}


//====================================================
HugeInt HugeInt :: operator/(int op2) const
{
	return *this / HugeInt(op2);				// call / operator after converting int to object
}


//====================================================
HugeInt HugeInt :: operator/(const string &op2) const
{
	return *this / HugeInt(op2);				// call / operator after converting string to object
}


//=========================== overloading "==" operator ==================================//

bool HugeInt:: operator==(const HugeInt &op2) const
{
	int flag = 0;

	for (int i = 0; i < digits; i++)
	{
		//check for all the sign conditions  
		if (integer[i] == op2.integer[i] && sign == '-' && op2.sign == '-') flag = 1;
		else flag = 0;
		if (integer[i] == op2.integer[i] && sign == '-' && op2.sign == '+') flag = 0;
		else flag = 1;
		if (integer[i] == op2.integer[i] && sign == '+' && op2.sign == '-') flag = 0;
		else flag = 1;
		if (integer[i] == op2.integer[i] && sign == '+' && op2.sign == '+') flag = 1;
		else flag = 0;
	}
	if (flag == 0)  return false;
	else			return true;
}


//====================================================
bool HugeInt:: operator==(int op2) const
{
	return *this == HugeInt(op2);
}


//====================================================
bool HugeInt:: operator==(const string & op2) const
{
	return *this == HugeInt(op2);
}


//=========================== overloading "!=" operator ==================================//

bool HugeInt:: operator!=(const HugeInt &op2) const
{
	int flag = 0;

	for (int i = 0; i < digits; i++)
	{
		// check for all conditions of signs
		if (integer[i] != op2.integer[i]) flag = 1;
		else flag = 0;
		if (integer[i] != op2.integer[i] || (sign == '-' && op2.sign == '+')) flag = 1;
		else flag = 0;
		if (integer[i] != op2.integer[i] || (sign == '+' && op2.sign == '-')) flag = 1;
		else flag = 0;
		if (integer[i] != op2.integer[i]) flag = 1;
		else flag = 0;
	}
	//return true is it is unequal
	if (flag == 0)  return false;
	else return true;
}

//====================================================
bool HugeInt:: operator!=(int op2) const
{
	return *this != HugeInt(op2);
}


//====================================================
bool HugeInt:: operator!=(const string & op2) const
{
	return *this != HugeInt(op2);
}


//=========================== overloading "<" operator ==================================//

bool HugeInt:: operator<(const HugeInt &op2) const
{
	int i = 0, j = 0;
	for (i = 0; i < HugeInt::digits && integer[i] == 0; ++i)
		; // skip leading zeros
	for (j = 0; j < HugeInt::digits && op2.integer[j] == 0; ++j)
		; // skip leading zeros

	for (; i < HugeInt::digits, j < HugeInt::digits, integer[i] == op2.integer[j]; i++, j++)
		;

	//  < if the signs 
	if (((sign == '+') && (op2.sign == '-')))	return false;
	else
	{
		if ((i >= j) || (integer[i] < op2.integer[j]) && ((sign == '-') && (op2.sign == '-')))	return true;
		else  if ((i >= j) || (integer[i] < op2.integer[j]) && ((sign == '+') && (op2.sign == '+')))	return true;
		else  if ((i >= j) || (integer[i] < op2.integer[j]) && ((sign == '-') && (op2.sign == '+')))	return true;
		else return false;
	}
}

//====================================================

bool HugeInt:: operator<(int op2) const
{
	return *this < HugeInt(op2);
}


//====================================================

bool HugeInt:: operator<(const string &op2) const
{
	return *this < HugeInt(op2);
}

//=========================== overloading ">" operator ==================================//

bool HugeInt::operator>(const HugeInt &op2) const
{
	int i = 0, j = 0;
	for (i = 0; i < HugeInt::digits && integer[i] == 0; ++i)
		; // skip leading zeros
	for (j = 0; j < HugeInt::digits && op2.integer[j] == 0; ++j)
		; // skip leading zeros
	for (; i < HugeInt::digits && j < HugeInt::digits && integer[i] == op2.integer[j]; i++, j++)
		;
	if (sign == '-' && op2.sign == '+') return false;
	else
	{
		if ((j >= i) || (integer[i] > op2.integer[j]))	return true;
		else  return false;
	}
}

//====================================================
bool HugeInt::operator>(int op2) const
{
	return *this > HugeInt(op2);
}

//====================================================
bool HugeInt::operator>(const string &op2) const
{
	return *this > HugeInt(op2);
}


//=========================== overloading "<=" operator ==================================//

bool HugeInt::operator<=(const HugeInt &op2) const
{
	int i = 0, j = 0;
	for (i = 0; i < HugeInt::digits && integer[i] == 0; ++i)
		; // skip leading zeros
	for (j = 0; j < HugeInt::digits && op2.integer[j] == 0; ++j)
		; // skip leading zeros


	if (((sign == '+') && (op2.sign == '-')))	return false;
	else
	{
		//-----< if different signs are there, then it will be unequal -------->
		if ((i >= j) || (integer[i] <= op2.integer[j]) && ((sign == '-') && (op2.sign == '-')))	return true;
		else  if ((i >= j) || (integer[i] <= op2.integer[j]) && ((sign == '+') && (op2.sign == '+')))	return true;
		else  if ((i >= j) || (integer[i] <= op2.integer[j]) && ((sign == '-') && (op2.sign == '+')))	return true;
		else return false;
	}
}

//====================================================

bool HugeInt::operator<=(int op2) const
{
	return *this <= HugeInt(op2);		// call <= operator after converting int to object
}

//====================================================

bool HugeInt::operator<=(const string &op2) const
{
	return *this <= HugeInt(op2);		// call <= operator after converting int to object
}

//=========================== overloading ">=" operator ==================================//

bool HugeInt::operator>=(const HugeInt &op2) const
{
	int i = 0, j = 0;
	for (i = 0; i < HugeInt::digits && integer[i] == 0; ++i)
		; // skip leading zeros
	for (j = 0; j < HugeInt::digits && op2.integer[j] == 0; ++j)
		; // skip leading zeros

		  // if both numbers are of different signs, then + will be greater than -
		  // irevelent of the magnitude, but cannot be equal
	if (sign == '-' && op2.sign == '+') return false;
	else
	{
		if ((j >= i) || (integer[i] >= op2.integer[j]))	return true;
		else  return false;
	}
}

//====================================================

bool HugeInt::operator>=(int op2) const
{
	return *this >= HugeInt(op2);			// call >= operator after converting int to object
}

//====================================================
bool HugeInt::operator>=(const string &op2) const
{
	return *this >= HugeInt(op2);			// call >= operator after converting int to object
}



//=========================== overloading "<<" operator ==================================//
// overloaded output operator
ostream& operator<<(ostream &output, const HugeInt &num)
{
	int i;

	for (i = 0; i < HugeInt::digits && num.integer[i] == 0; ++i)
		; // skip leading zeros
	if (num.sign == '+')
	{
		if (i == HugeInt::digits)	//HugeInt::digits  refers to the public digit
			output << 0;				//if even last digit is 0 print 0
		else
			for (; i < HugeInt::digits; ++i)
				output << num.integer[i];

		return output;
	}
	else
	{
		if (i == HugeInt::digits)	//HugeInt::digits  refers to the public digit
			output << 0;				//if even last digit is 0 print 0
		else
			output << num.sign;		// print the sign  of the number
		for (; i < HugeInt::digits; ++i)
			output << num.integer[i];

		return output;
	}
} // end function operator<<


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
