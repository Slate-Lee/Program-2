//Driver.cpp

#include <iostream>
#include "LinkedList.h"
#include "stateData.h"

int main () 
{
    LinkedList<State> list;

    stateData state;

    State state1("Tennessee", "Nashville", "Southeast", (1796));
    State state2("California", "Sacramento", "West", (1850));

    list.appendNode(state1);
    list.appendNode(state2);

    cout << "Initial State List:" << endl;
    list.displayList();

    int choice;

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
            state.Import();
            break;
        case 2:
            state.Add();
            break;
        case 3:
            state.Remove();
            break;
        case 4:
            state.Save();
            break;
        case 5:
            state.Display();
            break;
        case 6:
            state.Sort();
            break;
        }
    } while (choice != 7);

    cout << endl << "Goodbye!" << endl;

    return 0;
}
