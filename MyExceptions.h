//
// Created by Admin on 26/06/2018.
//

#ifndef EXERCISE3_MYEXCEPTIONS_H
#define EXERCISE3_MYEXCEPTIONS_H

#include <iostream>

using namespace std;

class MyExceptions {
public:

    class ProblemWithArguments{
    public:
        std::string s;
        ProblemWithArguments(const string& str): s(str) {}
        void print() { cout << s << endl;}
    };

    class InvalidCommand{
    public:
        std::string s;
        InvalidCommand(const string& str) : s(str) { }
        void print() {cout << s << endl;}
    };

};


#endif //EXERCISE3_MYEXCEPTIONS_H
