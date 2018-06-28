//
// Created by Admin on 19/06/2018.
//

#include <vector>
#include "Port.h"
#include "Ship.h"
#include "PatrolBoat.h"


void Port::update(){
    gasStoke += produce;
    std::weak_ptr<Ship> ship();
    if(!shipQueue.empty()) {
        std::weak_ptr<Ship> ship = shipQueue.front();
        ship.lock()->refuelAfterQue();
        shipQueue.pop_front();
    }
}

void Port::printStatus() {
    cout << "Port " << portName << " at position ";
    position.print();
    cout << ", Fuel available: " << setprecision(2) << gasStoke << " kl" << endl;
}

void Port::insertToGasQueue(std::vector<shared_ptr<Ship>>::iterator it) {
    shipQueue.push_back(*it);

}




