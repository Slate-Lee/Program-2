/*
	stateManager.h
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
    void remove(const string &stateName);
    void display() const;
};

#endif