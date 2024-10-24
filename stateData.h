#ifndef STATEDATA_H
#define STATEDATA_H

#include <iostream>
#include <string>
using namespace std;

class State
{
    private:
        string name;
        string capitol;
        string region;
        int yearFounded;
    public:
        State(){}
        State(string n, string c, string r, int y)
        {
            this->name = n;
            this->capitol = c;
            this->region = r;
            this->yearFounded = y;
        }

        // OVERLOADED OPERATOR <<
        friend ostream & operator << (ostream & os, State s)
		{
            os << endl << "State: " << s.name;
            os << endl << "Capitol: " << s.capitol;
            os << endl << "Region: " << s.region;
            os << endl << "yearFounded: " << s.yearFounded;

			return os;
		}

        // OVERLOADED

        // OVERLOADED

};

#endif