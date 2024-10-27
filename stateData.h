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

        ~State(){}

        void add();

        void remove();

        void sort();

        void display();

        void save();

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

        bool operator < (const State& other) const //These are what I got stackoverflow not sure what they do but powerpoint said we need them

        {
            return this->name < other.name;
        }

        bool operator > (const State& other) const 
        {
            return this->name > other.name;
        }

        bool operator == (const State& other) const 
        {
            return this->name == other.name;
        }

};

#endif
