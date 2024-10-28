#include "stateManager.h"
#include <iostream>
#include <fstream>

void StateManager::add()
{
    State state;
    state.add();
    stateList.appendNode(state);
    cout << "State successfully added." << endl;
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

void StateManager::save() const
{
    ofstream outFile;
    string fileName;
    LinkedList<State>::ListNode* current = stateList.head;

    // checks if there are movies in loading
    if (numOfStates > 0)
    {
        cin.ignore();

        cout << endl << "Type a file name (with '.txt') to create or overwrite: ";
        getline(cin, fileName);

        outFile.open(fileName, ios::out);
        if (outFile.is_open())
        {
            for (int i = 0; i < numOfStates; i++)
            {
                // UNFINISHED, NEEDS TO PRINT BACK TO THE TEXT FILE
            }
        }
        else
        {
            cout << "Failed to open file." << endl;
        }
    }
    else 
    {
        cout << endl << "There are no states to save. Please add or import states then try to save again." << endl;
    }

}

void StateManager::load()
{
    //
}
