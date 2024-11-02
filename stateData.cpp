/*
    stateData.cpp
*/

#include "LinkedList.h"
#include "stateData.h"
#include <fstream>

/*
    Function: add
    Purpose:  Allows user input the data about each state
*/
void State::add() 
{
    // asks the user for information about the state
    cin.ignore();
    cout << "Enter state name: ";
    getline(cin, name);
    cout << "Enter state capitol: ";
    getline(cin, capitol);
    cout << "Enter region: ";
    getline(cin, region);
    cout << "Enter year founded: ";
    cin >> yearFounded;
    cin.ignore();
}

/*
    Function: remove
    Purpose:  Allows user to enter the state's name and remove
            it from the linked list
*/
void State::remove() 
{
    // asks the user for the name of the state
    string stateName;
    cout << "Enter the name of the state to remove: ";
    cin >> stateName;

    LinkedList<State> stateList;
    int pos = 0;
    bool found = false;
    typename LinkedList<State>::ListNode* current = stateList.head;

    while (current != nullptr) 
    {
        if (current->value.name == stateName) 
        {
            // calls the deleteNode function
            stateList.deleteNode(pos);
            
            // prints confirmation and sets found to true
            cout << "State with memory address '" << stateName << "'successfully removed." << endl;
            found = true;
            break;
        }
        pos++;
        current = current->next;
    }
    if (!found) 
    {
        cout << "State not found." << endl;
    }
}

/*
    Function: display
    Purpose:  Displays all the state and their data in list
*/
void State::display() 
{
    LinkedList<State> stateList;
    stateList.displayList();
}