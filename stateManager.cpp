/*
	stateManager.cpp
*/

#include "stateManager.h"
#include <iostream>
#include <fstream>

void StateManager::initialAdd()
{

    State state1("Tennessee", "Nashville", "Southeast", 1796);
    State state2("California", "Sacramento", "West", 1850);
    State state3("New York", "Albany", "Northeast", 1788);
    State state4("Texas", "Austin", "Southwest", 1845);
    State state5("Florida", "Tallahassee", "Southeast", 1845);
    
    stateList.appendNode(state1);
    stateList.appendNode(state2);
    stateList.appendNode(state3);
    stateList.appendNode(state4);
    stateList.appendNode(state5);
    
    numOfStates = 5;

    cout << "Initial 5 states successfully added." << endl;
}

void StateManager::add()
{
    State state;
    state.add();
    stateList.appendNode(state);
    numOfStates++;
    cout << "State #" << numOfStates << "successfully added." << endl;
}

void StateManager::remove(const string &stateName)
{
    int position = 0;
    bool found = false;
    LinkedList<State>::ListNode *current = stateList.head;

    while (current != nullptr)
    {
        if (current->value.getName() == stateName)
        {
            stateList.deleteNode(position);
            cout << "State '" << stateName << "' removed successfully." << endl;
            
            found = true;
            break;
        }
        position++;
        current = current->next;
    }
    if (!found)
    {
        cout << "State not found." << endl;
    }
}

void StateManager::display() const
{
    stateList.displayList();
}