/////////////////////////////////////////////////////////////////////////////////////
// NodeSLList.h, The header file for the code contains functions and members       //
// the header NodeSLList.h                                                         //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: November 21th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
// Class NodeSLList Interface
//
// Description - This is the interface for a class which implements 
//               a singly linked list of integers. Each node in the 
//               linked list is IntNode object, defined by the IntNode
//               class. 
///////////////////////////////////////////////////////////////////////
#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

#include <iostream>

using std::ostream;
using std::cout;
using std::cin;
using std::endl;


struct IntNode
{
	int data;
	IntNode * next;
};


// Class NodeSLList Declaration

class NodeSLList {

	friend ostream & operator<<(ostream &, NodeSLList &);

public:


///////////////////////////////////////////////////////////////////////
// default constructor
// 
// Description: initialize list
// Input: none
// Output: none
// Returns: none
///////////////////////////////////////////////////////////////////////
	NodeSLList();

///////////////////////////////////////////////////////////////////////
// copy constructor
// 
// Description: initialize list from another list
// Input: none
// Output: none
// Returns: none
///////////////////////////////////////////////////////////////////////
	NodeSLList(NodeSLList &);

///////////////////////////////////////////////////////////////////////
// destructor
// 
// Description: deallocates all memory for linked list by calling
//              destroyList() member function
// Input: none
// Output: none
// Returns: none
///////////////////////////////////////////////////////////////////////
	~NodeSLList();

///////////////////////////////////////////////////////////////////////
// IsEmpty
// 
// Description: returns status of array
// Input: none
// Returns: TRUE if list is empty
//          FALSE otherwise
///////////////////////////////////////////////////////////////////////
	bool IsEmpty();

///////////////////////////////////////////////////////////////////////
// GetSize
// 
// Description: get current number of nodes in list
// Input: none
// Output: none
// Returns: number of nodes in list
///////////////////////////////////////////////////////////////////////
	int GetSize();

///////////////////////////////////////////////////////////////////////
// AddToHead
// 
// Description: add a node to the head of the list
// Input: data for node to be added
// Output: none
// Returns: none
///////////////////////////////////////////////////////////////////////
	void AddToHead(const IntNode & node);

///////////////////////////////////////////////////////////////////////
// DeleteFromHead
// 
// Description: remove a node from the head of the list
// Input: none
// Output: none
// Returns: data that was at the node just removed
///////////////////////////////////////////////////////////////////////
	IntNode DeleteFromHead();

///////////////////////////////////////////////////////////////////////
// AddToTail
// 
// Description: add a node to the tail of the list
// Input: data for node to be added
// Output: none
// Returns: none
///////////////////////////////////////////////////////////////////////
	void AddToTail(const IntNode & node);

///////////////////////////////////////////////////////////////////////
// DeleteFromTail
// 
// Description: remove a node from the tail of the list
// Input: none
// Output: none
// Returns: data that was at the node just removed
///////////////////////////////////////////////////////////////////////
	IntNode DeleteFromTail();

///////////////////////////////////////////////////////////////////////
// DeleteNode
// 
// Description: remove a node from the list
// Input: node number to be removed
// Output: none
// Returns: data that was at the node just removed
///////////////////////////////////////////////////////////////////////
	IntNode DeleteNode(int nodeNum);

///////////////////////////////////////////////////////////////////////
// InsertNode
// 
// Description: inserts a node in the list
// Input: node number after which a node is to be inserted
//        node data to be inserted
// Output: none
// Returns: data that was at the node just removed
///////////////////////////////////////////////////////////////////////
	void InsertNode(int nodeNum, const IntNode &node);


///////////////////////////////////////////////////////////////////////
// UpdateNode
// 
// Description: update a node's data
// Input: node number (1-N; not 0-(N-1))
// Output: none
// Returns: none
///////////////////////////////////////////////////////////////////////
	void UpdateNode(int nodeNum, const IntNode &node);

///////////////////////////////////////////////////////////////////////
// SortList
// 
// Description: sorts list
// Input: order (1=ascending, 2=descending)
// Output: none
// Returns: none
///////////////////////////////////////////////////////////////////////
	void SortList(unsigned int order);

///////////////////////////////////////////////////////////////////////
// DestroyList
// 
// Description: deallocates all memory for linked list
// Input: none
// Output: none
// Returns: none
///////////////////////////////////////////////////////////////////////
	void DestroyList();

///////////////////////////////////////////////////////////////////////
// operator=
// 
// Description: assignment operator
// Input: reference to NodeSLList object to be assigned
// Output: none
// Returns: NodeSLList object that has been assigned
///////////////////////////////////////////////////////////////////////
	NodeSLList & operator=(NodeSLList &);

///////////////////////////////////////////////////////////////////////
// operator==
// 
// Description: equality operator
// Input: reference to NodeSLList object to test equality with
// Output: none
// Returns: true if equal, false if not
///////////////////////////////////////////////////////////////////////
	bool operator==(NodeSLList &);

///////////////////////////////////////////////////////////////////////
// operator!=
// 
// Description: inequality operator
// Input: reference to NodeSLList object to test inequality with
// Output: none
// Returns: true if not equal, false if equal
///////////////////////////////////////////////////////////////////////
	bool operator!=(NodeSLList &);

///////////////////////////////////////////////////////////////////////
// operator+
// 
// Description: addition operator
// Input: reference to NodeSLList object to append to this one
// Output: none
// Returns: NodeSLList object that is the result of the addition operator
///////////////////////////////////////////////////////////////////////
	NodeSLList operator+(NodeSLList &);
	
private:


	IntNode *head, *tail;
	IntNode &RetrieveNode(int nodeNum) const; //helper function
	                                          //nodeNum is 
};

#endif INT_LINKED_LIST
