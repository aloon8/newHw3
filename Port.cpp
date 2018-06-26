//
// Created by Admin on 19/06/2018.
//

#include <vector>
#include "Port.h"
#include "Ship.h"

void Port::update(){

}

void Port::printStatus() {

}

bool Port::insertToGasQueue(std::vector<shared_ptr<Ship>>::iterator it) {
    std::weak_ptr<Ship> ship = *it;
    shipQueue.push_back(ship);
}


