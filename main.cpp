/////////////////////////////////////////////////////////////////////////////////////
// SelectionSort.h, The header file for the code contains functions and members    //
// the header file main.cpp                                                        //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: October 21th 2016                                                        //
/////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "SelectionSort.h"
#include "TimeStamp.h" 		// Include the timestamp header file
using namespace std;

					
template<class T> void addingRandomData(T &, int);           //Template declaration
template<class T> void PrintValues(T , int);
void copyArray(int[], int[] , int);


void main()
{
	srand(time(0));		// To generate random data
	int  flag = 0;		// 0 for descending and 1 for ascending

	const int smallArraySize = 20;						//Initialising the array size for the small/Large arrays/vectors
	const int largeArraySize = 7000;
	const int smallVectorSize = 20;
	const int largeVectorSize = 7000;

	SelectionSort mySelectionsort;                      //Creating the object from "SelectionSort" class

	int arraySmall[smallArraySize] = { 0 };			    // array declaration
	int arrayLarge[largeArraySize] = { 0 };
	int arraySmallCopy[smallArraySize] = { 0 };
	int arrayLargeCopy[largeArraySize] = { 0 };

	vector<int>inputVectorSmall(smallVectorSize);			//declaration of small vector
	vector<int>inputVectorLarge(largeVectorSize);			//declaration of large vector

	addingRandomData(arraySmall, smallArraySize);		    //Generating random numbers
	addingRandomData(arrayLarge, largeArraySize);

	copyArray(arraySmall, arraySmallCopy, smallArraySize);    //Helper function to make copy of small array
	copyArray(arrayLarge, arrayLargeCopy, largeArraySize);    //Helper function to make copy of large array

	addingRandomData(inputVectorSmall, smallVectorSize);      //Helper function to put random data in small vector
	addingRandomData(inputVectorLarge, largeVectorSize);      //Helper function to put random data in large vector

	vector<int>inputVectorSmallCopy(inputVectorSmall);        //Make a copy of small vector
	vector<int>inputVectorLargeCopy(inputVectorLarge);        //Make a copy of large vector

	cout << "If you would prefer descending so write 0 if you want ascending so please write 1" << endl;
	cin >> flag;
	///////////////////////////---------Array Sorting---------///////////////////////////
	cout << "///////////////////////////---------Array Sorting---------///////////////////////////" << endl;

	cout << "initial UNSORTED array is: [";
	PrintValues(arraySmall, smallArraySize);     //Helper function to print small array before sort
	cout << "]" << endl;

	mySelectionsort.RecursiveSort(arraySmall, smallArraySize, flag);         //Sort small array with recursion
	cout << "The finalized SORTED array with \"Recursion\" is: [";		     //Print sorted values
	PrintValues(arraySmall, smallArraySize);
	cout << "]" << endl;

	mySelectionsort.IterativeSort(arraySmall, smallArraySize, flag);         //Sort small array with iteration
	cout << "The finalized SORTED array with \"Iteration\" is: [";		     //Print sorted values
	PrintValues(arraySmall, smallArraySize);
	cout << "]" << endl;

	///////////////////////////---------Vector Sorting---------///////////////////////////
	cout << "///////////////////////////---------Vector Sorting---------///////////////////////////" << endl;

	cout << "initial UNSORTED vector is: [";
	PrintValues(inputVectorSmall, smallVectorSize);   //Helper function to print small vector before sort
	cout << "]" << endl;

	mySelectionsort.RecursiveSort(inputVectorSmall, smallVectorSize, flag);          //Sort small vector with recursion
	cout << "The finalized SORTED vector with \"Recursion\" is: [";
	PrintValues(inputVectorSmall, smallVectorSize);

	mySelectionsort.IterativeSort(inputVectorSmall, smallVectorSize, flag);          //Sort small array with iteration
	cout << "The finalized SORTED vector with \"Iteration\" is: [";		             //Print sorted values
	PrintValues(inputVectorSmall, smallArraySize);
	cout << "]" << endl;

	///////////////////////////---------Large Array---------///////////////////////////
	cout << "///////////////////////////---------Large Array---------///////////////////////////" << endl;
	
	cout << "print timestamp" << endl;             // Print timestamp
	string timeStep;
	TimeStamp ts;                                  // ts is of type timestamp

	timeStep = ts.GetTime();                       // Using TimeStamp to ask the current time
	cout << timeStep << endl;                      // current time printing
	cout << "sorting the large array with \"Recursion\"" << endl;
	mySelectionsort.RecursiveSort(arrayLarge, largeArraySize, flag);             // Sorting large array w/ recursion
	timeStep = ts.GetTime();                       // Using TimeStamp to ask the current time (after sorting)
	cout << timeStep << endl;                      // current time printing (again, after sorting)

	cout << endl;
	cout << endl;

	timeStep = ts.GetTime();                       // Using TimeStamp to ask the current time (before sorting)
	cout << timeStep << endl;                      // current time printing (before sorting)
	cout << "sorting the large array with \"Iteration\"" << endl;
	mySelectionsort.IterativeSort(arrayLarge, largeArraySize, flag);             // Sorting large array w/ iteration
	timeStep = ts.GetTime();                       // Using TimeStamp to ask the current time (after sorting)
	cout << timeStep << endl;                      // current time printing (again, after sorting)

	cout << endl;
	cout << endl;

	///////////////////////////---------Large Vector---------///////////////////////////
	cout << "///////////////////////////---------Large Vector---------///////////////////////////" << endl;
	
	timeStep = ts.GetTime();                       // Using TimeStamp to ask the current time (before sorting)
	cout << timeStep << endl;                      // current time printing (before sorting)
	cout << "sorting the large vector with \"Recursion\"" << endl;
	mySelectionsort.RecursiveSort(inputVectorLarge, largeVectorSize, flag);      // Sorting large vector w/ recursion
	timeStep = ts.GetTime();                       // Using TimeStamp to ask the current time (after sorting)
	cout << timeStep << endl;                      // current time printing (again, after sorting)

	cout << endl;
	cout << endl;

	timeStep = ts.GetTime();                       // Using TimeStamp to ask the current time (before sorting)
	cout << timeStep << endl;                      // current time printing (before sorting)
	cout << "sorting the large vector with \"Iteration\"" << endl;
	mySelectionsort.IterativeSort(inputVectorLarge, largeVectorSize, flag);      // Sorting large vector w/ iteration
	timeStep = ts.GetTime();                       // Using TimeStamp to ask the current time (after sorting)
	cout << timeStep << endl;                      // current time printing (again, after sorting)

}


//////////////////////////////////////////////////
//Function to make random number values
template <class T>
void addingRandomData(T &data, int size)
{
	for (int i = 0; i < size; i++) 
		data[i] = 1 + rand() % 100;
}

//Function to make a copy of array
void copyArray(int data[], int copyData[], int size)
{
	for (int j = 0; j < size; j++)
		copyData[j] = data[j];
}

//Function to print of values
template < class T >
void PrintValues(T data, int size)
{
	// output each student's grade
	for (int z = 0; z < size; z++)
		cout << data[z] << " ";
}
