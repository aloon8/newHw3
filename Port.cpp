//
// Created by Admin on 19/06/2018.
//

#include <vector>
#include "Port.h"
#include "Ship.h"


void Port::update(){
    gasStoke += produce;


}

void Port::printStatus() {

}

void Port::insertToGasQueue(std::vector<shared_ptr<Ship>>::iterator it) {
    shipQueue.push_back(*it);

}

bool Port::firstInQue(std::vector<shared_ptr<class Ship>>::iterator it) {
    if((*it) == shipQueue.front()){
        shipQueue.pop_front();
        return true;
    }
    return false;
}



