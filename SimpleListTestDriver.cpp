/////////////////////////////////////////////////////////////////////////////////////
// TestDriver.cpp, The header file for the code contains functions and members     //
// the header NodeSLList.h                                                         //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: November 21th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////


#include <cstdlib>
#include <ctime>

#include "NodeSLList.h"

void NodeSLList_Test();
void TestSort();

void main(void)
{
    NodeSLList_Test();
}

void NodeSLList_Test()
{

    NodeSLList list1;
	cout << "*****************************************************************************" << endl;
	cout << "Testing default constructor" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Creating NodeSLList list1" << endl;
    cout << "cout << list1 " << endl;
	cout << list1 << endl << endl;

    IntNode temp;

    IntNode n1;
	n1.data=10;
    IntNode n2;
	n2.data=20;
    IntNode n3;
	n3.data=30;
    IntNode n4;
	n4.data=40;
    IntNode n5;
	n5.data=50;

	cout << "*****************************************************************************" << endl;
    cout << "Testing AddToHead() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Adding " << n5.data << " to list1" << endl;
    list1.AddToHead(n5);
	cout << "Adding " << n4.data << " to list1" << endl;
    list1.AddToHead(n4);
	cout << "Adding " << n3.data << " to list1" << endl;
    list1.AddToHead(n3);
	cout << "Adding " << n2.data << " to list1" << endl;
    list1.AddToHead(n2);
	cout << "Adding " << n1.data << " to list1" << endl;
    list1.AddToHead(n1);
    cout << "cout << list1 " << endl;
    cout << list1 << endl;

	cout << "*****************************************************************************" << endl;
    cout << "Testing Copy Constructor. Creating list2 from list1" << endl;
	cout << "*****************************************************************************" << endl;
	
	NodeSLList list2(list1);   //Checking the copy constructor 
	cout << list2 << endl;
	cout << "Hello!" << endl;
	list2.SortList(0);
	cout << list2 << endl;
	
	cout << "*****************************************************************************" << endl;
	cout << "Testing AddToTail() operation" << endl;
	cout << "*****************************************************************************" << endl;
	NodeSLList list3;                    // Making an empty list3 to check if a new node can aslo be added to it 
	cout << "Adding " << n5.data << " to the end of list3" << endl;
	list3.AddToTail(n5);
	cout << list3 << endl;
	// Adding node to the curent list3
	cout << "Adding " << n4.data << " to the end of list3" << endl;
	list3.AddToTail(n4);
	cout << list3 << endl;


    cout << "*****************************************************************************" << endl;
	cout << "Testing GetSize() operation" << endl;
	cout << "*****************************************************************************" << endl;
    cout << "list1 contains " << list1.GetSize() << " node(s)" << endl << endl;

	cout << "*****************************************************************************" << endl;
    cout << "Testing operator= by assigning list1=list2" << endl;
	cout << "*****************************************************************************" << endl;
	NodeSLList list4;
	cout << list4 << endl;        // Printing the list 4
	cout << list1 << endl;        // Printing the list 2

	list4 = list1;                // Applying assignment operator
	cout << list4 << endl;        // Printing the list 4
	
	cout << "*****************************************************************************" << endl;
    cout << "Testing DeleteFromHead() operation" << endl;
	cout << "*****************************************************************************" << endl;
    temp = list1.DeleteFromHead();
    cout << "node retrieved " << temp.data << endl;
    cout << "cout << list1 " << endl;
    cout << list1 << endl;

	cout << "*****************************************************************************" << endl;
    cout << "Testing equality == and inequality != operators" << endl;
	cout << "*****************************************************************************" << endl;
	if ( list1 == list2 ) cout << "list1 == list2" << endl << endl;
	if ( list1 != list2 ) cout << "list1 != list2" << endl << endl;

	cout << "Putting the previous node back on the head of list1. Now list1 and list2 should be equal" << endl;
	list1.AddToHead(temp); 
    cout << "cout << list1 " << endl;
    cout << list1 << endl;

	cout << "*****************************************************************************" << endl;
    cout << "Testing equality == and inequality != operators" << endl;
	cout << "*****************************************************************************" << endl;
	cout << list2 << endl;
	if (list1 == list2) cout << "list1 == list2" << endl << endl;
	if (list1 != list2) cout << "list1 != list2" << endl << endl;


	cout << "*****************************************************************************" << endl;
	cout << "Testing DeleteFromTail() operation" << endl;
	cout << "*****************************************************************************" << endl;
    temp = list1.DeleteFromTail();
    cout << "node retrieved " << temp.data << endl;
    cout << "cout << list1 " << endl;
    cout << list1 << endl;

    cout << endl;
	cout << "Adding " << n3.data << " to head" << endl;
    cout << "Adding " << n2.data << " to head" << endl;
    list1.AddToHead(n3);
    list1.AddToHead(n2);
    cout << "cout << list1 " << endl;
	cout << list1 << endl;

	
	cout << "*****************************************************************************" << endl;
	cout << "Testing DeleteNode() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Deleting node 35 (should be last node, since 35 is beyond end of list)" << endl;
    temp = list1.DeleteNode(35);
    cout << "cout << list1 " << endl;
    cout << list1 << endl;
    temp = list1.DeleteNode(3);
    cout << "Deleteing node 3 (" << temp.data << ")" << endl;
    cout << "cout << list1 " << endl;
    cout << list1 << endl;


	cout << "*****************************************************************************" << endl;
	cout << "Testing InsertNode() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << list1 << endl;
	cout << "Inserting node 1 into 2nd element " << n1.data << " to list1" << endl;
	list1.InsertNode(2, n1);
	cout << "inserted list 1 using new node 1" << endl;
	cout << list1 << endl;
	

	cout << "*****************************************************************************" << endl;
    cout << "Testing IsEmpty() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "cout << list2 " << endl;
	cout << list2 << endl;
	cout << (list2.IsEmpty() ? "list2 is EMPTY" : "list2 is NOT EMPTY") << endl;


	cout << "*****************************************************************************" << endl;
    cout << "Testing UpdateNode() operation (updating 3rd node with 500)" << endl;
	cout << "*****************************************************************************" << endl;
    temp.data = 500;
    list1.UpdateNode(3,temp);
    cout << "cout << list1 " << endl;
    cout << list1 << endl;

	cout << "*****************************************************************************" << endl;
    cout << "Testing the ability to delete nodes from head." << endl;
	cout << "*****************************************************************************" << endl;
	cout << "list1 has " << list1.GetSize() << " nodes" << endl;
	int numNodesToDelete = list1.GetSize();
	for (int x=0; x<numNodesToDelete; x++)
	{
		cout << "Deleting from head" << endl;
		temp = list1.DeleteFromHead();
		cout << "cout << list1 " << endl;
		cout << list1 << endl;
	}
    cout << "Deleting from head, after list is empty. Should receive an error." << endl;
    temp = list1.DeleteFromHead();
    cout << "cout << list1 " << endl;
    cout << list1 << endl;
	
	cout << "*****************************************************************************" << endl;
	cout << "Testing DestroyList() operation" << endl;
	cout << "*****************************************************************************" << endl;
    cout << "cout << list2 " << endl;
    cout << list2 << endl;
    cout << "calling DestoryList()" << endl;
    list2.DestroyList();
    cout << "cout << list2 " << endl;
    cout << list2 << endl;

	cout << "*****************************************************************************" << endl;
    cout << "Test IsEmpty() operation" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "cout << list2 " << endl;
	cout << list2 << endl;
	cout << "calling list2.IsEmpty()" << endl;
	cout << (list2.IsEmpty() ? "list2 is EMPTY" : "list2 is NOT EMPTY") << endl << endl;


	cout << "*****************************************************************************" << endl;
	cout << "Testing SortList() operation, ascending" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "to ascending list 3" << endl;
	cout << "Adding " << n5.data << "&" << n2.data << "&" << n4.data << "&" << n1.data << "&" << n3.data << " to the end of list3" << endl;
	list3.AddToTail(n5);
	list3.AddToTail(n2);
	list3.AddToTail(n4);
	list3.AddToTail(n1);
	list3.AddToTail(n3);
	cout << list3 << endl;
	list3.SortList(0);
	cout << list3 << endl;
	
	cout << "*****************************************************************************" << endl;
	cout << "Testing SortList() operation, descending" << endl;
	cout << "*****************************************************************************" << endl;
	cout << "to descending list 4" << endl;
	list4.SortList(1);
	cout << list4 << endl;

	system ("pause");
}


