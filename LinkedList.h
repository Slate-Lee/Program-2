/*
	Class:   LinkedList
	Purpose: This LinkedList class template provides a general implementation
			for a singly linked list, allowing operations on a list of nodes holding
			values of any type T.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "stateData.h"

using namespace std;

template <typename T>
class LinkedList
{
public:
	// function members
	struct ListNode
	{
		T value;
		ListNode *next;
		ListNode *prev;
	};

	ListNode *head;
	ListNode *tail;
	int numNodes;

	/*
	Function: Constructor
	Purpose:  Initializes an empty linked list by setting head
			and tail to nullptr and numNodes to 0.
	*/
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		numNodes = 0;
	}
	~LinkedList();

	bool isEmpty() const;
	int getLength();
	void prependNode(T value);
	void insertNode(int position, T value);
	void appendNode(T value);
	void deleteNode(int position);
	void popNode();
	void displayList() const;

	// friend function
	friend ostream &operator<<(ostream &os, const LinkedList<T> &list)
	{
		list.displayList();
		return os;
	}
};

/*
	Function: Destructor
	Purpose:  Cleans up the linked list by deleting all nodes
			and freeing memory.
*/
template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode *currentNode = head;
	ListNode *nextNode;
	cout << endl;
	while (currentNode != nullptr)
	{
		nextNode = currentNode->next;
		cout << "Deleting node '" << currentNode->value << ".'" << endl;
		delete currentNode;
		currentNode = nextNode;
	}
}

/*
	Function: isEmpty
	Purpose:  Checks if the linked list is empty.
*/
template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return head == nullptr;
}

/*
	Function: getLength
	Purpose: Returns the length of the list.
*/
template <typename T>
int LinkedList<T>::getLength()
{
	return numNodes;
}
/*
	Function: prependNode
	Purpose: Places the new state at the beginning of the linked list.
*/
template <typename T>
void LinkedList<T>::prependNode(T value)
{
	// dynamically allocates for the new state and stores it in the list
	ListNode *newNode = new ListNode;
    newNode->value = value;
    newNode->next = head;
    newNode->prev = nullptr;
	
	// updates the head to point to the new node
	head = newNode;
    numNodes++;
}

/*
	Function: insertNode
	Purpose: Inserts node at a specified place
*/
template <typename T>
void LinkedList<T>::insertNode(int position, T value)
{
	// asks if the position is at the beginning
	if (position == 0)
	{
		ListNode *newNode = new ListNode;
		newNode->value = value;
		newNode->next = head;
		head = newNode;

		if (tail == nullptr)
		{
			tail = newNode;
		}
		numNodes++;
		return;
	}

	// sets pointers
	ListNode *currentNode = head;
	ListNode *prevNode = nullptr;

	// goes through the list to read the user inputted position
	for (int i = 0; i < position && currentNode != nullptr; i++)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
	}

	if (prevNode != nullptr)
	{
		ListNode *newNode = new ListNode;
		newNode->value = value;
		newNode->next = currentNode;
		prevNode->next = newNode;

		if (currentNode == nullptr)
		{
			tail = newNode;
		}
		numNodes++;
	}
}

/*
	Function: appendNode
	Purpose: Adds a new node with the given value to the end of the list
*/
template <typename T>
void LinkedList<T>::appendNode(T value)
{
	// dynamically allocates for the new state and stores it in the list
	ListNode *newNode = new ListNode;
	newNode->value = value;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	numNodes++;
}

/*
	Function: deleteNode
	Purpose:  Deletes the node at the specified position in the list
*/
template <typename T>
void LinkedList<T>::deleteNode(int position)
{
	// asks if the list is already empty
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

	ListNode *currentNode = head;
	ListNode *prevNode = nullptr;

	// asks if the position specified is zero
	if (position == 0)
	{
		head = head->next;
		delete currentNode;

		if (head == nullptr)
		{
			tail = nullptr;
		}
		numNodes--;
		return;
	}

	// goes through the list to the specified position
	for (int i = 0; i < position; i++)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
	}

	if (currentNode != nullptr)
	{
		prevNode->next = currentNode->next;

		delete currentNode;

		if (prevNode->next == nullptr)
		{
			tail = prevNode;
		}
	}
	numNodes--;
}

/*
	Function: popNode
	Purpose: Removes the last added state
*/
template <typename T>
void LinkedList<T>::popNode()
{
	
	if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
	
	ListNode *currentNode = head;
	ListNode *prevNode = nullptr;

	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		numNodes--;
		return;
	}

	while (currentNode->next != nullptr)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
	}

	prevNode->next = nullptr;
	tail = prevNode;
	delete currentNode;
	numNodes--;
}

/*
	Function: displayList
	Purpose: Outputs the values of all nodes in the list
*/
template <typename T>
void LinkedList<T>::displayList() const
{
	ListNode *currentNode;
	currentNode = head;
	int i = 1;

	while (currentNode != nullptr)
	{
		cout << endl
			<< "STATE " << i;
		cout << currentNode->value << endl;

		currentNode = currentNode->next;
		i++;
	}
}

#endif