//
// Created by Admin on 19/06/2018.
//

#ifndef EXERCISE3_PORT_H
#define EXERCISE3_PORT_H

#include <iostream>
#include <queue>
#include <memory>
#include "Geometry.h"



class Port {
public:

    Port(const std::string portName,const Point& pos, const int GasStoke, const int produce ) : portName(portName), position(pos)
                                                                                                ,gasStoke(GasStoke), produce(produce){

    }



private:
    std::string portName;
    queue<weak_ptr<class Ship>> queue;
    Point position;
    int gasStoke;
    const int produce;
};


#endif //EXERCISE3_PORT_H
