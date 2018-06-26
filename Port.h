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

    const string &getPortName() const {
        return portName;
    }

    void setPortName(const string &portName) {
        Port::portName = portName;
    }

    const Point &getPosition() const {
        return position;
    }

    void setPosition(const Point &position) {
        Port::position = position;
    }

    int getGasStoke() const {
        return gasStoke;
    }

    void setGasStoke(int gasStoke) {
        Port::gasStoke = gasStoke;
    }

    const int getProduce() const {
        return produce;
    }

private:
    std::string portName;
    queue<weak_ptr<class Ship>> myQueue;
    Point position;
    int gasStoke;
    const int produce;
};


#endif //EXERCISE3_PORT_H
