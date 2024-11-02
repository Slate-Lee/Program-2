/*
    stateManager.cpp
*/

#include "stateManager.h"
#include <iostream>
#include <fstream>

/*
    Function: initialAdd
    Purpose:  Adds all intial state data to the linked list
*/
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

/*
    Function: add
    Purpose:  Adds states to linked list
*/

void StateManager::add()
{
    int answer = 0;
    int position = 0;
    State state;
    state.add();

    // asks the user in what way they want to add the new state
    cout << "Do you want to insert or append?" << endl << "1 - prepend" << endl
        << "2 - insert" << endl << "3 - append";
    cout << "\nCHOOSE: 1-3: ";
    cin >> answer;
    if (answer == 1)
    {
        // adds state to beginning
        stateList.prependNode(state);
    }
    else if (answer == 2)
    {
        // asks the user to specify where they want the state
        cout << "Where do you want to insert (from 1-" << stateList.getLength() << ")?";
        cin >> position;
        stateList.insertNode(position, state);
    }
    else
    {
        // adds state to the end
        stateList.appendNode(state);
    }
    numOfStates++;
    cout << "State successfully added." << endl;
}

/*
    Function: remove
    Purpose:  Removes the state data from the linked list
*/

void StateManager::remove()
{
    int answer;
    int position = 0;
    string stateName;
    bool found = false;
    LinkedList<State>::ListNode *current = stateList.head;

    // asks the user how they want to remove the state
    cout << "Do you want to pop or remove state by name" << endl << "1 - pop" << endl << "2 - by name";
    cout << "\nCHOOSE: 1-2: ";
    cin >> answer;
    if (answer == 1)
    {
        // removes state from the end
        stateList.popNode();
    }
    else
    {
        // asks the user to specify which state they want to add
        cout << "Please name the state: ";
        cin >> stateName;
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
}

/*
    Function: display
    Purpose:  Displays all the state and their data in list
*/
void StateManager::display() const
{
    stateList.displayList();
}