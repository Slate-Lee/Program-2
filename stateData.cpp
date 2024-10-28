#include "LinkedList.h"
#include "stateData.h"
#include <fstream>

void State::import()
{
    
}

void State::add() 
{
    cout << "Enter state name: ";
    cin >> name;
    cout << "Enter state capitol: ";
    cin >> capitol;
    cout << "Enter region: ";
    cin >> region;
    cout << "Enter year founded: ";
    cin >> yearFounded;
}

void State::remove() 
{
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
            stateList.deleteNode(pos);
            cout << "State with memory adress '" << stateName << "'successfully removed." << endl;
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

void State::sort()
{
    
}

void State::display() 
{
    LinkedList<State> stateList;
    stateList.displayList();
}

void State::save() 
{
    LinkedList<State> stateList;
    ofstream outFile("state_data.txt");
    if (!outFile) 
    {
        cout << "Error opening file for writing." << endl;
        return;
    }
    typename LinkedList<State>::ListNode* current = stateList.head;
    while (current != nullptr) 
    {
        outFile << current->value;
        current = current->next;
    }
    outFile.close();
    cout << "State data saved to file successfully." << endl;
}
