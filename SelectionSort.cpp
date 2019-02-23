/////////////////////////////////////////////////////////////////////////////////////
// SelectionSort.h, The header file for the code contains functions and members    //
// the header file SelectionSort.cpp                                               //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: October 21th 2016                                                        //
/////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <ctime>
#include"SelectionSort.h"            //Including the class selectionsort header
using namespace std;


//asending function definition for array and vector
template < class T >
void  SelectionSort::ascendingSort(T &inputData, int size)
{
	int maxIndex = 0, insert = 0, index = 0;
	for (index = maxIndex; index < size; index++) {
		if (inputData[index] > inputData[maxIndex]) {
			maxIndex = index;
		}
	}
	insert = inputData[size - 1];
	inputData[size - 1] = inputData[maxIndex];
	inputData[maxIndex] = insert;

	if (size > 1) {
		ascendingSort(inputData, --size);
	}
}

//Descending function definition for array and vector
template < class T >
void  SelectionSort::descendingSort(T &inputData, int size) 
{
	int maxIndex = 0, insert = 0, index = 0;
	for (index = maxIndex; index < size; index++) {
		if (inputData[index] < inputData[maxIndex]) {
			maxIndex = index;
		}
	}
	insert = inputData[size - 1];
	inputData[size - 1] = inputData[maxIndex];
	inputData[maxIndex] = insert;

	if (size > 1) {
		descendingSort(inputData, --size);
	}
}


// Using Recursive method to sort array
void SelectionSort::RecursiveSort(int inputData[], int size, int flag)
{
	// 0 for descending and 1 for ascending 
	switch (flag)
	{
	case 0:                                       //descending
		descendingSort(inputData, size);          //Using this function we can decrease numbers
		break;
	case 1:                                       //ascending
		ascendingSort(inputData, size);           //Using this function we can increase numbers
		break;
	}
}

//Using Iterative method to sort array
void SelectionSort::IterativeSort(int inputData[], int size, int flag) 
{
	switch (flag)
	{
	// 0 for descending and 1 for ascending 
	case 0:                                                              // Creating a loop for the elements of the array                                
		for (int next = 1; next < size; next++)
		{
			int insert = inputData[next];                                   // locate the value in the same element   
			int moveItem = next;                                            // initialize location to locate element       
			// search for the location in which to put the current element     
			while ((moveItem > 0) && (inputData[moveItem - 1] < insert))
			{                         
				inputData[moveItem] = inputData[moveItem - 1];             // Shift the element one slot to the right 
				moveItem--;
			}                                                               // end while                                                     
			inputData[moveItem] = insert;                                   // Place inserted element into the array
		}                                                                   // end for
		break;

	case 1:                            
		for (int next = 1; next < size; next++)                           // Creating a loop for the elements of the array 
		{
			int insert = inputData[next];                                 // locate the value in the same element  
			int moveItem = next;                                          // initialize location to locate element       
			// search for the location in which to put the current element     
			while ((moveItem > 0) && (inputData[moveItem - 1] > insert))
			{                     
				inputData[moveItem] = inputData[moveItem - 1];             // shift element one slot to the right     
				moveItem--;
			}                                                              // end while                                                     
			inputData[moveItem] = insert;                                  // place inserted element into the array
		}                                                                  // end for  
		break;
	}
}

//This section is for vector sort - recursive
void SelectionSort::RecursiveSort(vector< int > &inputData, int size, int flag) 
{
	switch (flag)
	{
	// 0 for descending and 1 for ascending 
	case 0:
		descendingSort(inputData, size);                                //Using this function we can decrease numbers
		break;
	case 1:
		ascendingSort(inputData, size);                                 //Using this function we can increase numbers
		break; 
	}
}

//This section is for vector sort - iterative
void SelectionSort::IterativeSort(vector< int > &inputData, int size, int flag)
{
	switch (flag)
	{
	// 0 for descending and 1 for ascending 
	case 0:                                                             //descending                               
		for (int next = 1; next < size; next++)                         // Creating a loop for the elements of the array
		{
			int insert = inputData[next];                               // locate the value in the same element    
			int moveItem = next;                                        // initialize location to locate element      
		    // search for the location in which to put the current element     
			while ((moveItem > 0) && (inputData[moveItem - 1] < insert))
			{                       
				inputData[moveItem] = inputData[moveItem - 1];          // move the element one slot to the right   
				moveItem--;
			}                                                            // end while                                                     
			inputData[moveItem] = insert;                                // place inserted element into the array
		}                                                                // end for
		break;
	case 1:                                                              //ascending																 
		for (int next = 1; next < size; next++)                          // Creating a loop for the elements of the array                            
		{
			int insert = inputData[next];                                     // locate the value in the same element   
			int moveItem = next;                                              // initialize location to locate element       
			// search for the location in which to put the current element     
			while ((moveItem > 0) && (inputData[moveItem - 1] > insert))
			{                       
				inputData[moveItem] = inputData[moveItem - 1];          // ,pve the element one slot to the right   
				moveItem--;
			}                                                             // end while                                                     
			inputData[moveItem] = insert;                                 // locate the value in the same element   
		}                                                                 // end for  
		break;
	}
	return;
}




