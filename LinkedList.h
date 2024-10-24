#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedList
{
	private:
		struct ListNode
		{
			T value;
			ListNode *next;
		}; 

		ListNode *head;	
		ListNode *tail;		

	public:
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}
		~LinkedList();
		void appendNode(T value);
		void deleteNode(int position);
		void displayList() const;
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
		cout << "Deleting node with memory address: " << currentNode  << "." << endl;
		delete currentNode;
		currentNode = nextNode;
	}
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
void LinkedList<T>::displayList() const 
{
	ListNode *currentNode;
	currentNode = head;
	int i = 1;

	while (currentNode != nullptr)
	{
		cout << endl << "*****NODE " << i << " WITH MEMORY ADDRESS: " << currentNode << ".";
		cout << currentNode->value << endl;

		currentNode = currentNode->next;
		i++;
	}
}

#endif