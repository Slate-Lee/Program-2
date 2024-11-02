/*
    Class:   stateManager
    Purpose: This StateManager class provides functionality to manage a collection
            of State objects, allowing the user to add, remove, display, and save
            these states to a file.
*/

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "LinkedList.h"
#include "stateData.h"
#include <string>

class StateManager
{
private:
    LinkedList<State> stateList;
    int numOfStates;

public:
    StateManager() : numOfStates(0) {}
    ~StateManager() = default;

    void initialAdd();
    void add();
    void remove();
    void display() const;
};

#endif