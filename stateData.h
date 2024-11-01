/*
	stateData.h
*/

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
        void display();

        State(string n, string c, string r, int y)
        {
            this->name = n;
            this->capitol = c;
            this->region = r;
            this->yearFounded = y;
        }

        string getName() const{
            return name;
        }

        // OVERLOADED OPERATOR <<
        friend ostream & operator << (ostream & os, State s)
		{
            os << endl << "\tState: " << s.name;
            os << endl << "\tCapitol: " << s.capitol;
            os << endl << "\tRegion: " << s.region;
            os << endl << "\tyearFounded: " << s.yearFounded;

			return os;
		}

        bool operator<=(const State& other) const {
            return this->name <= other.name;
        }

        bool operator>=(const State& other) const {
            return this->name >= other.name;
        }

        bool operator<(const State& other) const {
            return this->name < other.name;
        }

        bool operator>(const State& other) const {
            return this->name > other.name;
        }

        bool operator == (const State& other) const 
        {
            return this->name == other.name;
        }

};

#endif
