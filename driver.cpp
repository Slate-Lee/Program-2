/*
	Driver.cpp
*/

#include <iostream>
#include "LinkedList.h"
#include "stateData.h"
#include "stateManager.h"

int main () 
{
    StateManager manager;
    int choice;
    string stateName;
    
    LinkedList<State> list;

    manager.initialAdd(); // adds fives states automatically

    cout << "Initial State List:" << endl;
    manager.display();

    do
    {
        // menu options
        cout << "\n Menu Options: ";
        cout << "\n1 - Add";
        cout << "\n2 - Remove";
        cout << "\n3 - Display";
        cout << "\n4 - Exit Program";

        do
        {
            cout << "\nCHOOSE: 1-5: ";
            cin >> choice;
            if (choice < 1 || choice > 4) 
            {
                cout << endl << "Invalid choice." << endl;
            }
        } while (choice < 1 || choice > 4);

        switch (choice)
        {
        case 1:
            manager.add();
            break;
        case 2:
            cout << endl << "Enter state name to remove: ";
            cin >> stateName;
            manager.remove(stateName);
            break;
        case 3:
            manager.display();
            break;
        }
    } while (choice != 4);

    cout << endl << "Goodbye!" << endl;
    return 0;
}
