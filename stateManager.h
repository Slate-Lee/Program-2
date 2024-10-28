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
    StateManager() = default;
    ~StateManager() = default;

    void add();
    void remove(const string &stateName);
    void display() const;
    void save() const;
    void load();
};

#endif