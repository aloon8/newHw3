//
// Created by Admin on 19/06/2018.
//

#ifndef EXERCISE3_PORT_H
#define EXERCISE3_PORT_H

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include "Geometry.h"



class Port {
public:

    Port(const std::string portName,const Point& pos, const int GasStoke, const int produce ) : portName(portName), position(pos)
                                                                                                ,gasStoke(GasStoke), produce(produce){

    }

    bool insertToGasQueue(std::vector<shared_ptr<class Ship>>::iterator it);

    void update();

    void printStatus();

    friend bool operator==(std::weak_ptr<Port> port1 ,std::weak_ptr<Port> port2){
        return port1.lock()->portName==port2.lock()->portName;
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
    list<weak_ptr<Ship>> shipQueue;
    Point position;
    int gasStoke;
    const int produce;
};


#endif //EXERCISE3_PORT_H
