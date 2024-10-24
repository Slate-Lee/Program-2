#include "LinkedList.h"
#include "stateData.h"

int main () {

    LinkedList<State> list;

    State state1("Tennessee", "Nashville", "Southeast", (1796));
    State state2("California", "Sacramento", "West", (1850));

    list.appendNode(state1);
    list.appendNode(state2);
    list.displayList();
    
    return 0;
}