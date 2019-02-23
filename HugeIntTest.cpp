
/////////////////////////////////////////////////////////////////////////////////////
// HugeIntTest.cpp, The header file for the code contains functions and members    //
// the header HugeInt.h                                                            //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: November 27th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////




// HugeInt test program.
#include <iostream>
#include "Hugeint.h"
using namespace std;

int main()
{
	HugeInt n1(7654321, '+');
	HugeInt n2(7891234, '+');
	HugeInt n3("99999999999999999999999999999", '+');
	HugeInt n4("1", '+');
	HugeInt result;

	cout << "n1 is " << n1 << "\nn2 is " << n2 << "\nn3 is " << n3 << "\nn4 is " << n4 << "\nresult is " << result << "\n\n";
		
	//=========================== testing "+" operator ==================================//

	cout << "====================== Summation (+) operator testing ======================" << endl;
	result = n1 + n2;		//addition of two objects
	cout << n1 << " + " << n2 << " = " << result << "\n\n";

	cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

	result = n1 + 9;			//adding integer to object
	cout << n1 << " + " << 9 << " = " << result << endl;

	result = n2 + "10000";	// adding string to object
	cout << n2 << " + " << "10000" << " = " << result << endl;

	//=========================== testing "-" operator ==================================//

	cout << "\n\n\n";
	cout << "====================== Subtraction (-) operator testing ======================" << endl;
	HugeInt s1(50145453, '+');
	HugeInt s2(25943434, '-');
	HugeInt s3("99999999999999999999999999999", '+');
	HugeInt s4(999, '+');
	int s5 = 123151;
	result = n2 - n1;		// subtracting two objects
	cout << n2 << " - " << n1 << " = " << result << "\n\n";
	result = s1 - s2;
	cout << s1 << " - " << s2 << " = " << result << "\n\n";
	result = s1 - "5453";		// subtract string from Hugeint
	cout << "(string) " << s1 << " - " << "5453 " << " = " << result << "\n\n";
	result = s1 - 123151;		// subtract integer frin HugeInt
	cout << " (int) " << s1 << " - " << s5 << " = " << result << "\n\n";
	result = s3 - "999";
	cout << " (hugeint) " << s3 << " - " << s4 << " = " << result << "\n\n";

	//=========================== testing "*" operator ==================================//

	cout << "\n\n\n";
	cout << "=================== Multiplication (*) operator testing ===================" << endl;
	HugeInt m1(1212, '+');
	HugeInt m2(2020, '+');
	int m3 = 65;
	HugeInt m4(100000, '+');
	HugeInt m5(2020, '-');
	result = m1 * m2;		// Multiplying two objects
	cout << "(obj) * (obj) " << m1 << " * " << m2 << " = " << result << endl;
	cout << "\n\n";
	result = m1 * 65;				// multiplying objects with integers
	cout << " (obj)*(int) " << m1 << " * " << m3 << " = " << result << endl;
	cout << "\n\n";
	result = m4 * "99999999999999999999999999999";	// multiply string with object
	cout << " (obj)*(huge int) " << m4 << " * " << n3 << " = " << result << endl;
	cout << "\n\n";
	result = m1 * m5;
	cout << "(obj) * (-obj)" << m1 << " * " << m5 << " = " << result << endl;
	cout << "\n\n";

	//=========================== testing "/" operator ==================================//


	cout << "\n\n\n";
	cout << "====================== Division (/) operator testing ======================" << endl;
	HugeInt d1(164255, '+');
	HugeInt d2(23465, '-');
	HugeInt d3(164255, '-');
	int d4 = 5;
	HugeInt d5("21470000000", '+');
	HugeInt d6(10000000, '+');

	result = d1 / d1;
	cout << d1 << "/" << d1 << " = " << result << endl;
	cout << "\n";
	result = d1 / d2;
	cout << d1 << "/" << d2 << "(obj/obj) = " << result << endl;
	cout << "\n";
	result = d3 / 5;		// dividing object with integer
	cout << d3 << "/" << d4 << "(obj/int) = " << result << endl;
	cout << "\n";
	result = d5 / "10000000";		// dividing object with string
	cout << d5 << "/" << d6 << "(hugeint/string) = " << result << endl;
	cout << "\n";

	//=========================== testing "==" operator ==================================//

	cout << "\n\n\n";
	cout << "====================== Relational (==) operator testing ======================" << endl;
	HugeInt e1(252525252, '+');
	HugeInt e2(2525, '+');

	cout << "\n\n";
	HugeInt e3(25252525, '+');
	HugeInt e4(25252525, '+');
	if (e3 == e4)    cout << "e3 =  " << e3 << "\t" << "e4 =  " << e4 << "\n" << " They are equal " << endl;
	else   cout << " They are not equal " << endl;

	cout << "\n\n";
	HugeInt e11(25252525, '+');
	HugeInt e12(25252525, '-');
	HugeInt e13(31254, '-');

	// checking if two objects are equal
	if (e11 == e12)    cout << "e11 =  " << e11 << "\t" << "e12 (-) =  " << e12 << "\n" << "They are equal" << endl;
	else   cout << "e11 =  " << e11 << "\t" << "e12 (-) =  " << e12 << "\n" << "They are not equal" << endl;

	cout << "\n";
	HugeInt e5(123123, '+');
	int	   e6 = 123123;
	if (e5 == e6)	cout << "e5 =  " << e5 << "\t" << "e6 (int) =  " << e6 << "\n" << "They are equal" << endl;
	else   cout << "e5 =  " << e5 << "\t" << "e6 (int) =  " << e6 << "\n" << "They are not equal" << endl;

	cout << "\n";
	HugeInt e7(123123, '+');
	int	e8 = 1231;
	if (e7 == 1231)	cout << "e7 =  " << e7 << "\t" << "e8 (int) =  " << e8 << "\n" << "They are equal" << endl;
	else   cout << "e7 =  " << e7 << "\t" << "e8(int) =  " << e8 << "\n" << "They are not equal" << endl;
	// checking for equality of huge numbers > 32 bit
	cout << "\n";
	HugeInt e9("99999999999999999999999999999", '+');
	if (e9 == "99999999999999999999999999999")	cout << "e9 (num>32bit) =  " << e9 << "\t" << "n3 =  " << n3 << "\n" << "They are equal" << endl;
	else   cout << "e9(num>32bit) =  " << e9 << "\t" << "n3 =  " << n3 << "\n" << "They are not equal" << endl;

	cout << "\n";
	HugeInt e10("9099099999099999909999909990", '+');
	if (e10 == "99999999999999999999999999999")	cout << "e10 =  " << e10 << "\t" << "n3 =  " << n3 << "\n" << "They are equal" << endl;
	else   cout << "e10 =  " << e10 << "\t" << "n3 =  " << n3 << "\n" << "They are not equal" << endl;


	//=========================== testing "!=" operator ==================================//

	cout << "\n\n\n";
	cout << "====================== != operator testing ======================" << endl;
	if (e13 != e12)    cout << "e13 =  " << e13 << "\t" << "e12  =  " << e12 << "\n" << "They are not equal" << endl;
	else   cout << "e11 =  " << e13 << "\t" << "e12 (-) =  " << e12 << "\n" << "They are  equal" << endl;
	cout << "\n";
	if (e1 != e2)	cout << "e1 =  " << e1 << "\t" << "e2 =  " << e2 << "\n" << "They are not equal" << endl;
	else				cout << "e1 =  " << e1 << "\t" << "e2 =  " << e2 << "\n" << "They are  equal" << endl;
	cout << "\n";
	// checking if two objects are not equal
	if (e3 != e4)	cout << "e3 =  " << e3 << "\t" << "e4 =  " << e4 << "\n" << "They are not equal" << endl;
	else cout << "e3 =  " << e3 << "\t" << "e4 =  " << e4 << "\n" << "They are  equal" << endl;
	cout << "\n";
	cout << "\n";
	if (e7 != 1231)	cout << "e7 =  " << e7 << "\t" << "e8 (int) =  " << e8 << "\n" << "They are not equal" << endl;
	else cout << "e7 =  " << e7 << "\t" << "e8(int) =  " << e8 << "\n" << "They are  equal" << endl;
	cout << "\n";
	if (e9 != "99999999999999999999999999999")	cout << "e9 (num>32bit) =  " << e9 << "\t" << "n3 =  " << n3 << "\n" << "They are not equal " << endl;
	else            cout << "e9(num>32bit) =  " << e9 << "\t" << "n3 =  " << n3 << "\n" << "They are  equal" << endl;
	// checking for inequality of huge numbers > 32 bit
	cout << "\n";
	if (e10 != "99999999999999999999999999999")	cout << "e10 =  " << e10 << "\t" << "n3 =  " << n3 << "\n" << "They are not equal " << endl;
	else cout << "e10 =  " << e10 << "\t" << "n3 =  " << n3 << "\n" << "They are equal " << endl;
	cout << "\n";


	//=========================== testing "<" operator ==================================//

	cout << "\n\n\n";
	cout << "====================== < operator testing ======================" << endl;
	if (n1 < n2) cout << n1 << " is less than " << n2 << endl;
	else cout << n1 << " is not less than " << n2 << endl;
	cout << "\n";
	//checking if one object is less than other object
	if (e2 < e1) cout << e2 << " is less than " << e1 << endl;
	else cout << e2 << "  is not less than  " << e1 << endl;
	cout << "\n";
	if (e5 < e12) cout << e5 << " is less than " << e12 << endl;
	else  cout << e5 << "  is not less than  " << e12 << endl;
	cout << "\n";
	// comparision between object and integer
	if (e2 < 123123) cout << e2 << " is less than (int) " << e6 << endl;
	else cout << e2 << "  is not less than  " << e6 << endl;
	cout << "\n";
	if (e9 < e1) cout << e1 << "(num>32bit) is less than " << e9 << endl;
	else cout << e9 << "  is not less than  " << e1 << endl;
	cout << "\n";
	// comparing is two huge numbers > 32 bit are less than one another 
	if (e1 < "99999999999999999999999999999") cout << e1 << " is less than (num>32bit) " << e9 << endl;
	else cout << e1 << "  is not less than  " << e9 << endl;
	
	//=========================== testing "<=" operator ==================================//

	cout << "\n\n\n";
	cout << "====================== <= operator testing ======================" << endl;
	HugeInt e14(25252525, '-');
	if (e3 <= e4) cout << e3 << " is less than or equal to " << e4 << endl;
	else cout << e3 << " is not less than or equal to " << e4 << endl;
	cout << "\n";
	if (e2 <= e6) cout << e2 << " is less than or equal to (int) " << e6 << endl;
	else cout << e2 << " is not less than or equal to " << e6 << endl;
	cout << "\n";
	//checking if one object is less than or equal to other object
	if (e9 <= e1) cout << e1 << "(num>32bit) is less than or equal to " << e9 << endl;
	else cout << e9 << " is not less than or equal to " << e1 << endl;
	cout << "\n";
	if (e1 <= e9) cout << e1 << " is less than or equal to(num>32bit) " << e9 << endl;
	else cout << e1 << " is not less than or equal to " << e9 << endl;
	cout << "\n";
	if (e12 <= e14) cout << e12 << " is less than or equal to " << e14 << endl;
	else cout << e12 << " is not less than or equal to " << e14 << endl;
	cout << "\n";
	if (e2 <= e13) cout << e2 << " is less than or equal to " << e13 << endl;
	else cout << e2 << " is not less than or equal to " << e13 << endl;
	
	//=========================== testing ">" operator ==================================//

	cout << "\n\n\n";
	cout << "====================== > operator testing ======================" << endl;
	if (n2 > n1) cout << n2 << " is greater than " << n1 << endl;
	else cout << n2 << " is not greater than " << n1 << endl;
	cout << "\n";
	//checking if one object is greater than other object
	if (n1 > e13) cout << n1 << " is greater than " << e13 << endl;
	else cout << n1 << " is not greater than " << e13 << endl;
	cout << "\n";
	if (e12 > e7) cout << e12 << " is greater than " << e7 << endl;
	else cout << e12 << " is not greater than " << e7 << endl;
	cout << "\n";
	cout << "\n";
	if (e1 > e2) cout << e1 << " is greater than " << e2 << endl;
	else cout << e1 << " is not greater than " << e2 << endl;
	cout << "\n";
	if (n2 > 123123) cout << n2 << " is greater than (int) " << e6 << endl;
	else cout << e2 << " is not greater than " << e6 << endl;
	cout << "\n";
	// comparing is two huge numbers > 32 bit are greater than one another 
	if (e1> "99999999999999999999999999999") cout << e1 << " is greater than (num>32bit) " << e9 << endl;
	else cout << e1 << " is not greater than " << e9 << endl;

	//=========================== testing ">=" operator ==================================//

	cout << "\n\n\n";
	cout << "====================== >= operator testing ======================" << endl;

	if (e3 >= e4) cout << e1 << " is greater than or equal to" << e2 << endl;
	else cout << e3 << " is not greater than or equal to " << e4 << endl;
	cout << "\n";
	if (e9 >= e1) cout << e9 << "(num>32bit) is greater than or equal to" << e1 << endl;
	else cout << e9 << " is not greater than or equal to " << e1 << endl;
	cout << "\n";
	// comparing is two huge numbers > 32 bit are greater than or equal to one another
	if (e1 >= "99999999999999999999999999999") cout << e1 << " is greater than or equal to(num>32bit)" << e9 << endl;
	else cout << e1 << " is not greater than or equal to " << e9 << endl;
	cout << "\n\n";
	if (e12 >= e14) cout << e12 << " is greater than or equal to" << e14 << endl;
	else cout << e12 << " is not greater than or equal to " << e14 << endl;
	cout << "\n";
	if (e2 >= e13) cout << e2 << " is greater than or equal to" << e13 << endl;
	else cout << e2 << " is not greater than or equal to " << e13 << endl;

	cout << "====================== End of the testing ======================" << endl;
	return 0;
} // end main


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
