#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedList
{
	public:
		struct ListNode
				{
					T value;
					ListNode *next;
				}; 

				ListNode *head;	
				ListNode *tail;
				int numNodes;

		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
			numNodes = 0;
		}
		~LinkedList();

		bool isEmpty() const;
		int getLength();
		void appendNode(T value);
		void insertNode(int position, T value);
		void deleteNode(int position);
		void displayList() const;
		void swap(ListNode* node1, ListNode* node2);
		T getFront() const;
    
		friend ostream& operator<<(ostream &os, const LinkedList<T> &list) 
		{
			list.displayList();
			return os;
		}
};

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode *currentNode = head;
	ListNode *nextNode;
	cout << endl;
	while (currentNode != nullptr)
	{
		nextNode = currentNode->next;
		cout << "Deleting state '" << currentNode << ".'" << endl;
		delete currentNode;
		currentNode = nextNode;
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	if(!head)
		return true;
	else
		return false;
}

template <typename T>
int LinkedList<T>::getLength()
{
	return numNodes;
}

template <typename T>
void LinkedList<T>::appendNode(T value)
{
	// Initializing
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
		tail = newNode;
	}
}

template <typename T>
void LinkedList<T>::deleteNode(int position)
{
	ListNode *currentNode = head;
	ListNode *prevNode = nullptr;

	if (position == 0)
	{
		head = head->next;
		delete currentNode;

		if (head == nullptr)
		{
			tail = nullptr;
		}

		return;
	}

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
}

template <typename T>
void LinkedList<T>::swap(ListNode* node1, ListNode* node2)
{
    T temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

template <typename T>
void LinkedList<T>::displayList() const 
{
	cout << endl << "about to display list...";
	ListNode *currentNode;
	currentNode = head;
	int i = 1;

	cout << endl << (currentNode != nullptr);
	while (currentNode != nullptr)
	{
		cout << endl << "STATE " << i << " WITH MEMORY ADDRESS: " << currentNode << ".";
		cout << currentNode->value << endl;

		currentNode = currentNode->next;
		i++;
	}
}

template <typename T>
T LinkedList<T>::getFront() const
{
	if (isEmpty())
	{
		cout << "List is empty.";
	}
	return head->value;
}

#endif
