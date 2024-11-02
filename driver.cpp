/*
    Driver.cpp
    Purpose: This files runs the menu system for the program
        which allows the user to choose to display the state
        data, add, remove, and exit the program. The beginning
        of the program also calls the "initialAdd" function,
        which places 5 states in the list automatically.
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

    // adds fives states automatically
    manager.initialAdd();

    cout << "\n\nInitial State List:" << endl;
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
            cout << "\nCHOOSE: 1-4: ";
            cin >> choice;

            // input validation
            if (choice < 1 || choice > 4) 
            {
                cout << endl << "Invalid choice." << endl;
            }
        } while (choice < 1 || choice > 4);

        // switch case which calls various functions based on user input
        switch (choice)
        {
        case 1:
            manager.add();
            break;
        case 2:
            manager.remove();
            break;
        case 3:
            manager.display();
            break;
        }
    } while (choice != 4);

    // Goodbye message and the end of the program
    cout << endl << "Goodbye!" << endl;
    return 0;
}