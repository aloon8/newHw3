//
// Created by Admin on 19/06/2018.
//

#include "PatrolBoat.h"

PatrolBoat::PatrolBoat(const std::string& shipName, const Point& pos, int Resistance) :
        Ship(shipName, pos), Resistance(Resistance),myType(PB),existInQueueGas(false){
    visitedPorts.insert(visitedPorts.begin(),Model::getInstance().getSizeOfPortVector(),false);
}

int PatrolBoat::getResistance() const {
    return Resistance;
}

void PatrolBoat::setResistance(int Resistance) {
    PatrolBoat::Resistance = Resistance;
}

void PatrolBoat::Moving(weak_ptr<class Port> port, int speed) {
    if(status == Ship::Status::MovingTo || status == Ship::Status::DeadInTheWater){
        //throw canot do this move
    }
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

void PatrolBoat::update() {
    if(status == Ship::Status::Docked){
        docked();
    }
    else if(status == Ship::Status::MovingTo){
        stepOnWater();
        Point p1 =  trackBase.getPosition();
        Point p2 =  trackBase.getPort().lock()->getPosition();
        if(p1 == p2){
            setStatus(Ship::Status::Docked);
        }
    }

}

void PatrolBoat::docked() {
    if(status == Ship::Status::Docked) {
        switch (numOfMoves) {
            case 0:
                if(trackBase.getPort().lock()->insertToGasQueue(Model::getInstance().findShip(name)))
                break;
            case 1:
                numOfMoves++;
                break;
            case 2:
                setStatus(Ship::Status::MovingTo);
                trackBase.setMovingWay(TrackBase::ByPort);
                auto closePort = givesTheCloserPort();
                if(closePort.lock() == nullptr) {
                    cout << "The boat: " << name << "finished it's round" << endl;
                    return;
                }
                trackBase.setPort(closePort);
                numOfMoves = 0;
                break;
        }
    }
}

void PatrolBoat::stepOnWater() {

}

std::weak_ptr<Port> PatrolBoat::givesTheCloserPort() {
    auto vectOfPorts = Model::getInstance().getPortVec();
    std::shared_ptr<Port> theClosePort(nullptr);

    for(int i=0; i<vectOfPorts.size(); i++){
        if(visitedPorts[i] == true){
            continue;
        }
        if(theClosePort == nullptr){
            theClosePort = vectOfPorts[i];
        }
        if(trackBase.getPosition().distance(theClosePort->getPosition()) >
                trackBase.getPosition().distance(vectOfPorts[i]->getPosition()) ){
            theClosePort = vectOfPorts[i];
        }
    }
    return theClosePort;
}


