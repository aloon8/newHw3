//
// Created by Admin on 19/06/2018.
//

#include "PatrolBoat.h"

PatrolBoat::PatrolBoat(const std::string& shipName, const Point& pos, int Resistance) :
        Ship(shipName, pos), Resistance(Resistance),Gas(MAX_GAS_PATROL),myType(PB){
    visitedPorts.insert(visitedPorts.begin(),Model::getInstance().getSizeOfPortVector(),false);
}

int PatrolBoat::getResistance() const {
    return Resistance;
}

void PatrolBoat::setResistance(int Resistance) {
    PatrolBoat::Resistance = Resistance;
}

void PatrolBoat::Moving(weak_ptr<class Port> port, int speed) {
    if((status == Ship::Status::MovingTo && trackBase.getMovingWay() == TrackBase::ByPort) || status == Ship::Status::DeadInTheWater){
        //throw canot do this move
    }
    setStatus(Ship::Status::MovingTo);
    trackBase.setMovingWay(TrackBase::ByPort);
    trackBase.setPort(port);
    trackBase.setSpeed(speed);
    std::fill(visitedPorts.begin(),visitedPorts.end(),false);
    int indexOfPort = givesIndexOfPort(port);
    visitedPorts[indexOfPort] = true;
    index = indexOfPort;
}

void PatrolBoat::update() {
    if(status == Ship::Status::Docked){
        docked();
    }
    else if(status == Ship::Status::MovingTo){
        stepOnWater();
        decreaseGas();
    }
    else if(status == Ship::Status::DeadInTheWater){
        //throw dead in water
    }

}

void PatrolBoat::docked() {
    switch (numOfMoves) {
        case 0:
            if(Ship::refuel())
                numOfMoves++;
            break;
        case 1:
            numOfMoves++;
            break;
        case 2:
            setStatus(Ship::Status::MovingTo);
            trackBase.setMovingWay(TrackBase::ByPort);
            auto closePort = givesTheCloserPort();
            if(closePort.lock() == nullptr) {
                /*need to add return to the first port*/
                //
                //
                cout << "The boat: " << name << "finished it's round" << endl;
                return;
            }
            trackBase.setPort(closePort);
            int indexOfPort = givesIndexOfPort(closePort);
            visitedPorts[indexOfPort] = true;
            numOfMoves = 0;
            break;
    }
}


std::weak_ptr<Port> PatrolBoat::givesTheCloserPort() {//this function will gives the port closest
    auto vectOfPorts = Model::getInstance().getPortVec();
    std::shared_ptr<Port> theClosePort(nullptr);

    for(int i=0; i<vectOfPorts.size(); i++){
        if(visitedPorts[i] == true){//the ship visited in this port and this round
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

void PatrolBoat::refuelAfterQue() {
    auto port  = trackBase.getPort().lock();
    if((port->getGasStoke()+Gas) <= MAX_GAS_PATROL){
        Gas += port->getGasStoke();
        port->setGasStoke(0);
    }
    else{
        int x = MAX_GAS_PATROL - Gas;
        Gas += x;
        port->setGasStoke(port->getGasStoke() - x);
    }
}

void PatrolBoat::printStatus() const {

    cout << "Patrol_boat " << name << " at ";
    trackBase.getPosition().print();
    cout << ", fuel: " << setprecision(2)<< Gas << " kl, resistance: "
         << Resistance << ", ";

    if(status == Ship::MovingTo)
        printMoveWay();
    else if(status == Ship::Status::Stopped)
        cout << "Stopped";
    else if(status == Ship::Status::DeadInTheWater)
        cout << "Dead in the water";
    else
        cout << "Docked at " << trackBase.getPort().lock()->getPortName();
    cout << endl;

}

int PatrolBoat::givesIndexOfPort(std::weak_ptr<Port> port) {
    int i=0;
    for(std::weak_ptr<Port> x : Model::getInstance().getPortVec()){
        if(x == port)
            break;
        i++;
    }
    return i;
}

void PatrolBoat::decreaseGas() {
    Gas -= trackBase.getSpeed()*GAS_USE_PER_NM_PATROL;
    if(Gas <=0){//if the ship doesn't have gas she change her status to dead in water
        setStatus(Ship::Status::DeadInTheWater);
        Gas = 0;
    }
}


