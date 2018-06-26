//
// Created by Admin on 19/06/2018.
//

#include "PatrolBoat.h"

PatrolBoat::PatrolBoat(const std::string& shipName, const Point& pos, int Resistance) : Ship(shipName, pos), Resistance(Resistance),myType(PB){
    visitedPorts.insert(visitedPorts.begin(),Model::getInstance().getSizeOfPortVector(),false);
}

int PatrolBoat::getResistance() const {
    return Resistance;
}

void PatrolBoat::setResistance(int Resistance) {
    PatrolBoat::Resistance = Resistance;
}

void PatrolBoat::Moving(weak_ptr<class Port> port, int speed) {
    setStatus(Ship::Status::MovingTo);
    trackBase.setMovingWay(TrackBase::ByPort);
    trackBase.setPort(port);
    trackBase.setSpeed(speed);
    std::fill(visitedPorts.begin(),visitedPorts.end(),false);
    int i=0;
    for(std::weak_ptr<Port> x : Model::getInstance().getPortVec()){
        if(x == port)
            break;
        i++;
    }
    visitedPorts[i] = true;
    index = i;
}

void PatrolBoat::currentMove() {

}

