//
// Created by raviv on 6/17/18.
//

#ifndef EXERCISE3_CONTROLLER_H
#define EXERCISE3_CONTROLLER_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <iterator>
#include "Model.h"
#include "Geometry.h"
#include "MyExceptions.h"
#include "View.h"

using namespace std;

class Controller {

public:
    Controller(int argc, char* argv[]);

    void initPorts(int argc, char* argv[]);

    void run();

    static const int MAX_SPEED_PATROL = 15;

    static const int MAX_SPEED_FREIGHTER = 40;

    static const int MAX_SPEED_CRUISER = 75;

    void initVectorCommands();

private:
    int hashing(std::string);

    inline bool isNumber(const std::string& s) {
        return !s.empty() &&
               std::find_if(s.begin(), s.end(), [](char c) { return !(std::isdigit(c) || c == '.'); }) == s.end();
    }
    //View view;
    std::vector<string> vecOfCommands;

    View view;
};


#endif //EXERCISE3_CONTROLLER_H
