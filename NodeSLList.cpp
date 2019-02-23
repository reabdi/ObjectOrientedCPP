/////////////////////////////////////////////////////////////////////////////////////
// NodeSLList.cpp, The header file for the code contains functions and members     //
// the header NodeSLList.h                                                         //
// Course Name: Object Oriented Programming CIS-554                                //
// Author: Reza ABdi, SUNcol-ESF                                                   //
//         email: reabdi@scolr.edu, SUID: reabdi                                   //
// Build: November 21th 2016                                                       //
/////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
// Class NodeSLList Implementation
//
// Description - This file implements a singly linked list.
///////////////////////////////////////////////////////////////////////
#include "NodeSLList.h"


///////////////////////////////////////////////////////////////////////
// default constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList()
{ 
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// copy constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList(NodeSLList & list)
{
	head = tail = 0;

	IntNode *l = list.head;       // Creating a list for moving into a node to make another list
						          // for calculating the number of nodes 
	while (l != NULL)
	{
		IntNode *node = new IntNode;          // New node
									          // until reaching the tail, it will continue
		node->data = l->data;                 // Taking data from head for trandfering
		node->next = 0;
		AddToTail(*node);                     //using addtotail function to add the node the tail
		l = l->next;
	}
}

///////////////////////////////////////////////////////////////////////
// destructor
///////////////////////////////////////////////////////////////////////
NodeSLList::~NodeSLList()
{
	// call destroyList() to remove all nodes
	// and reset linked list
	DestroyList();
}

///////////////////////////////////////////////////////////////////////
// IsEmpty
///////////////////////////////////////////////////////////////////////
bool NodeSLList::IsEmpty()
{ 
	// if head is NULL, then the list is empty, and we will return true
	// otherwise, we will return false
	return (head == 0); 
}

///////////////////////////////////////////////////////////////////////
// GetSize
///////////////////////////////////////////////////////////////////////
int NodeSLList::GetSize()
{
	// check to see if the list is empty. if 
	// so, just return 0
	if ( IsEmpty() ) return 0;

	int size = 1;
	IntNode *p = head;
	// compute the number of nodes and return
	while (p != tail)
	{
		// until we reach the tail, keep counting
		size++;
		p = p->next;
	}
	return size;
}

///////////////////////////////////////////////////////////////////////
// AddToHead
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToHead(const IntNode & node)
{
	// create a new node, and make it the head. the 
	// previous head will become head->next
	IntNode * next = head;
	head = new IntNode;
	head->next = next;
	head->data = node.data;

	// if this is the first node, make the tail the 
	// same as the head
	if (tail == 0)
		tail = head;
}

///////////////////////////////////////////////////////////////////////
// DeleteFromHead
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromHead()
{
	IntNode temp;
	temp.data=0;
	temp.next=NULL;
	if (IsEmpty())
	{
		cout << "*****ERROR: Can't delete from head. List is Empty" << endl;
		return temp;
	}

	// get current value of node we are about to delete, 
	// so we can return it.
	temp.data = head->data;

	IntNode *tmp = head;

	// if there is only one node, set the head and pointer tails
	// to NULL (0)
	if (head == tail)
		head = tail = 0;

	// otherwise, move the head pointer to the next node 
	// in the list
	else
		head = head->next;

	// delete head node
	delete tmp;

	// return value of node that was deleted
	return temp;
}

///////////////////////////////////////////////////////////////////////
// AddToTail
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToTail(const IntNode & node)
{
	if (head == 0)
	{
		IntNode *l = new IntNode;                        // Creating new node
		l->data = node.data;                             // getting data from user and transfering into node
		l->next = NULL;                                  // pointing next node which is tail here to zero
		tail = head = l;                                 // In case we have just one node, make both head and tail equal to l
	}
	else {
		IntNode *tailold = tail;                         // To get the current node as a node called tailold
		tail = new IntNode;                              // Make new node as a correct tail
		tail->data = node.data;                          // Getting data from user and transfering into tail
		tail->next = 0;                                  // Pointing tail to the null
		IntNode * next = tail;
		tailold->next = next;
	}
}

///////////////////////////////////////////////////////////////////////
// DeleteFromTail
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromTail()
{
	IntNode nodeData;

	// get the current data at the tail
	nodeData.data = tail->data;


	// if there is only one node, delete the only node, and set the 
	// head and tail pointers to NULL (0) 
	if (head == tail)
	{
		delete head;
		head = tail =0;
	}

	// otherwise, traverse to the tail node and delete it
	else
	{
		IntNode * temp;
		// traverse to tail pointer
		for (temp = head; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = 0;
	}

	return nodeData;
}


///////////////////////////////////////////////////////////////////////
// DeleteNode
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteNode(int nodeNum)
{
	if (nodeNum <= 0) nodeNum = 1;
	IntNode *prev=head , *temp=head;
	IntNode current;

	// traverse to the node
	for (int loop=1; loop<nodeNum; loop++)
	{
		prev=temp, temp=temp->next;
		// check for case where nodeNum is > the number of 
		// nodes in the list. if we reach the tail before
		// we traverse to the node, delete the tail 
		if ( temp == tail )
			return DeleteFromTail();
	}

	// if deleting the head just call 
	// the appropriate member function 
	// and don't repeat that logic here
	if (temp == head) return DeleteFromHead();

	// otherwise, delete the node we traversed to
	prev->next = temp->next;
	current.data = temp->data;

	delete temp;

	return current;
}

///////////////////////////////////////////////////////////////////////
// InsertNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::InsertNode(int nodeNum, const IntNode &node)
{
	IntNode *node1 = new IntNode;                      // Making new node
	node1->data = node.data;                           // Sending data into new node
	node1->next = NULL;

	if (IsEmpty())                                      // assign head and tail to the node if it is empty
		head = tail = node1;

	if (nodeNum < 1)        // If the numbers are less than one for the position of new node, the new node will be added to the head
		AddToHead(*node1);
	else
	{
		IntNode *tmp = head;
		// If the number is more than number of nodes in list, then the new node would be added
		for (int i = 1; i< nodeNum && tmp != tail; i++)
			tmp = tmp->next;

		node1->data = tmp->data;
		node1->next = tmp->next;
		tmp->data = node.data;
		tmp->next = node1;

		if ((node1->next) == NULL)
			tail = node1;              // Making the new tail
	}
}


///////////////////////////////////////////////////////////////////////
// UpdateNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::UpdateNode(int nodeNum, const IntNode &node)
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first. if the last node is reached, then that is the node
	// that is updated
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	tmp->data = node.data;
}

///////////////////////////////////////////////////////////////////////
// SortList
///////////////////////////////////////////////////////////////////////
void NodeSLList::SortList(unsigned int order)
{
	if (head == tail)             // If they are the same there is no need to sort
		return;

	switch (order)
	{
	case 0:                      // Ascending sorting
	{
		int count = 0, i;
		IntNode *start = head;
		IntNode *temp = NULL;
		IntNode *curr = NULL;
		IntNode *trail = NULL;

		// Counting the grab
		while (start != NULL) { 
			count++;
			start = start->next;
		}
		for (i = 0; i < count; ++i) {          // All of the elements in the list

			curr = trail = head;               // Setting curr and trail at the beginning node

			while (curr->next != NULL) {       // For the rest of the elements in the list
				if (curr->data > curr->next->data) {        // Compareing curr and curr->next

					temp = curr->next;                      // Swap pointers for curr and curr->next
					curr->next = curr->next->next;
					temp->next = curr;

					// Now I need to setup pointers for trail and maybe the head
					if (curr == head)             // This is the case of the first element swapping to preserve the head pointer
						head = trail = temp;
					else                          //setup trail correctly
						trail->next = temp;
					curr = temp;                  // Updateing curr to be temp since the positions changed
				}
				// And here the advance pointers
				trail = curr;
				curr = curr->next;
			}
		}
	}

	case 1: // Descending sorting
	{
		int count = 0, i;
		IntNode *start = head;
		IntNode *temp = NULL;
		IntNode *curr = NULL;
		IntNode *trail = NULL;

		// Counting the grab
		while (start != NULL) { 
			count++;
			start = start->next;
		}

		for (i = 0; i < count; ++i) {             // For all of the elements in the list

			curr = trail = head;                  // Setting curr and trail at the start node

			while (curr->next != NULL) {          // For the rest of the elements in the list
				if (curr->data < curr->next->data) {         // Compareing curr and curr->next

					temp = curr->next;                       // Swap pointers for curr and curr->next
					curr->next = curr->next->next;
					temp->next = curr;

					// Now I need to setup pointers for trail and maybe the head
					if (curr == head)              // This is the case of the first element swapping to preserve the head pointer
						head = trail = temp;
					else                            //setup trail correctly
						trail->next = temp;
					curr = temp;                    // Updateing curr to be temp since the positions changed
				}
				// And here the advance pointers
				trail = curr;
				curr = curr->next;
			}
		}
	}
  }
}

///////////////////////////////////////////////////////////////////////
// DestroyList
///////////////////////////////////////////////////////////////////////
void NodeSLList::DestroyList()
{
	// while the list is NOT empy
	// keep removing the head node and make
	// the next node the head node
	for (IntNode *p; !IsEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// operator=
///////////////////////////////////////////////////////////////////////
NodeSLList & NodeSLList::operator=(NodeSLList & list)
{
	IntNode *current = list.head;             // Pointing out to the head of input list
	IntNode *newnode = new IntNode;           // Creating new node
	IntNode * head1 = newnode;                // Saving head of another list

	for (; current->next != NULL;)            //Sending data from inputed list by user into the another list
	{
		newnode->data = current->data;

		newnode->next = new IntNode;
		newnode = newnode->next;
		current = current->next;
	}
	newnode->data = current->data;
	newnode->next = NULL;
	head = head1;
	tail = current;
	return *this;                            // Here I have the new list 
}

///////////////////////////////////////////////////////////////////////
// operator==
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator==(NodeSLList & list)
{
	// Looking for if the size of two list are the same
	int a = this->GetSize();
	int b = list.GetSize();

	if (a != b)
		return false;            // In case lists dont have the same size

	// Making pointers to heads of each list
	IntNode *p = this->head;
	IntNode *pl = list.head;
	// Checking whole same size lists node by node nad comparig their data
	while (p != 0)
	{

		if (p->data == pl->data)
		{
			p = p->next;
			pl = pl->next;
		}
		else
			// In case one of the nodes, data is not similar to the node of the other list, they are not equal
			return false;
	}
	// These lists are equal if they are in the same size and old values of each of the nodes are the similar
	return true;
}

///////////////////////////////////////////////////////////////////////
// operator!=
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator!=(NodeSLList & list)
{
	return !(*this == list);        // I need the oppsite of this operator
}

///////////////////////////////////////////////////////////////////////
// operator+
///////////////////////////////////////////////////////////////////////
NodeSLList NodeSLList::operator+(NodeSLList & list)
{
	NodeSLList result;
	result.head = result.tail = 0;

	// Creating pointers to the current nodes of each list
	IntNode *pl = list.head;
	IntNode *p2 = this->head;
	IntNode *pr = result.head;
	// Creatnig new list to get summation

	// Calculating the number of nodes and returning them
	while (pl != NULL)
	{
		// Creating a new node to put the summation result
		IntNode *node = new IntNode;
		// Until it reachs the tail, keep going
		node->data = pl->data + p2->data;
		node->next = 0;

		// Adding the new node which is result to the tail of the result list
		if (result.head == 0)
		{
			IntNode *node1 = new IntNode;
			node1->data = node->data;
			node1->next = NULL;
			result.tail = result.head = node1;
		}

		else
		{
			IntNode *tailold = result.tail;
			result.tail = new IntNode;
			result.tail->data = node->data;
			result.tail->next = 0;
			IntNode * next = result.tail;

			tailold->next = next;
		}

		// Moving to next nodes
		pl = pl->next;
		p2 = p2->next;

	}

	return result;
}

///////////////////////////////////////////////////////////////////////
// RetrieveNode
// 
// Description: retrieve data from a node without removing it from 
//              the list
// Input: node number (1-N; not 0-N-1)
// Output: none
// Returns: reference to node data
///////////////////////////////////////////////////////////////////////
IntNode & NodeSLList::RetrieveNode(int nodeNum) const
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	return *tmp;
}

ostream & operator<<(ostream & output, NodeSLList & list)
{
	IntNode *p = list.head;

	while (p != NULL)
	{
		output << p->data << ", ";
		p = p->next;
	}

	return output;
}

