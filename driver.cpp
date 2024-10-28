//Driver.cpp

#include <iostream>
#include "LinkedList.h"
#include "stateData.h"
#include "stateManager.h"

int main () 
{
    /*LinkedList<State> list;

    State state;

    State state1("Tennessee", "Nashville", "Southeast", (1796));
    State state2("California", "Sacramento", "West", (1850));

    list.appendNode(state1);
    list.appendNode(state2);

    cout << "Initial State List:" << endl;
    list.displayList();*/

    StateManager manager;
    int choice;
    string stateName;

    do
    {
        // menu options
        cout << "\n Menu Options: ";
        cout << "\n1 - Import";
        cout << "\n2 - Add";
        cout << "\n3 - Remove";
        cout << "\n4 - Save";
        cout << "\n5 - Display";
        cout << "\n6 - Sort";
        cout << "\n7 - Exit Program";

        do
        {
            cout << "\nCHOOSE: 1-7: ";
            cin >> choice;
            if (choice < 1 || choice > 7) 
            {
                cout << endl << "Invalid choice." << endl;
            }
        } while (choice < 1 || choice > 7);

        switch (choice)
        {
        case 1:
            //manager.import();
            break;
        case 2:                     // ADD - WORKING
            manager.add();
            break;
        case 3:                     // REMOVE - WORKING
            cout << endl << "Enter state name to remove: ";
            cin >> stateName;
            manager.remove(stateName);
            break;
        case 4:
            manager.save();
            break;
        case 5:                     // DISPLAY - WORKING
            manager.display();
            break;
        case 6:
            //manager.sort();
            break;
        }
    } while (choice != 7);

    cout << endl << "Goodbye!" << endl;

    return 0;
}
