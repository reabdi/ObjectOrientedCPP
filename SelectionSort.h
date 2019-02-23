/////////////////////////////////////////////////////////////////////////////////////
// SelectionSort.h, The header file for the code contains functions and members    //
// the header file SelectionSort.h                                                 //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNY-ESF                                                     //
//         email: reabdi@syr.edu, SUID: reabdi                                     //
// Build: October 21th 2016                                                        //
/////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

// Class defination
class SelectionSort {

public:                                                   
	template < class T >void ascendingSort(T &, int size);               //Function to sort in increasing order
	template < class T >void descendingSort(T &, int size);              //Function to sort in decreasing order
	void IterativeSort(int[], int, int);                                 //for array                           
	void IterativeSort(vector<int> &, int, int);                         //for vector
	void RecursiveSort(int[], int, int);	                             //for array
	void RecursiveSort(vector<int> &, int, int);                         //for vector
};
