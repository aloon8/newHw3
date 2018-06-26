//
// Created by Admin on 19/06/2018.
//

#include "Port.h"

void Port::update(){

}

void Port::printStatus() {

}

bool Port::insertToGasQueue(std::weak_ptr<class Ship> ship) {
    if(shipQueue.empty())
        return true;
    shipQueue.push(ship);
    return false;
}
