//
// Created by raviv on 6/17/18.
//

#include <sstream>
#include "Freighter.h"
#include "Model.h"

//Freighter::MAX_GAS = 500000;



Freighter::Freighter(std::string shipName, const Point& pos,int Resistance,int Containers) : Ship(shipName, pos), Resistance(Resistance)
        , Containers(Containers), Gas(MAX_GAS_FREIGHTER), myType(FR), loadStatus(LoadingStatus::NotLoadOrUnload)
        , maxContainers(Containers){}

int Freighter::getResistance() const {
    return Resistance;
}

void Freighter::setResistance(int Resistance) {
    Freighter::Resistance = Resistance;
}

int Freighter::getContainers() const {
    return Containers;
}

void Freighter::setContainers(int Containers) {
    Freighter::Containers = Containers;
}

int Freighter::getGas() const {
    return Gas;
}

void Freighter::setGas(int Gas) {
    Freighter::Gas = Gas;
}

void Freighter::update() {
    if(status == Ship::Status::Docked){
        docked();
    }
    else if(status == Ship::Status::MovingTo){
        stepOnWater();
        decreaseGas();
    }
    else if(status == Ship::Status::DeadInTheWater){
        //throw dead in the water
    }
}

void Freighter::Moving(weak_ptr<class Port> port, int speed) {
    if((status == Ship::Status::MovingTo && trackBase.getMovingWay() == TrackBase::ByPort) || status == Ship::Status::DeadInTheWater){
    //throw canot do this move
        return;
    }
    if(status == Docked){
        if(existInMissionQue()){
            //she need to unload or load in this port
        }
        else if(existInQueueGas) {
            cout << "the ship need rufuel" << endl; //the ship in gas queue
        }
        return;
    }
    setStatus(Ship::Status::MovingTo);
    trackBase.setMovingWay(TrackBase::ByPort);
    trackBase.setPort(port);
    trackBase.setSpeed(speed);
}


void Freighter::load_at(std::weak_ptr<Port> port) {
    std::pair<std::string,std::string> load{port.lock()->getPortName(), "load"};
    missionQue.emplace_back(port.lock()->getPortName(), "load");
}

void Freighter::unload_at(std::weak_ptr<Port> port, int containers) {
    stringstream os{};
    os << containers;
    missionQue.emplace_back(std::make_pair(port.lock()->getPortName(),os.str()));
}

void Freighter::docked() {//when the ship docks
    auto begin = missionQue.begin();
    auto end = missionQue.end();
    for(; begin != end; begin++){//Checks if the ship has a command of load or unload from the port that is docked
        if((*begin).first == trackBase.getPort().lock()->getPortName())
        break;
    }
    if(begin != end){//if the vector have this port its means that have a command to do
        if((*begin).second == "load"){
            Containers = maxContainers;
        }
        else{
            stringstream iss{(*begin).second};
            int numOfContainers;
            iss >> numOfContainers;
            if(numOfContainers > Containers){
                Containers = 0;
                cout << "Warnings the ship " << name << "doesn't have enough containers to unload " << endl;
            }
            else{
                Containers -= numOfContainers;
            }
        }
        missionQue.erase(begin);
    }
}

void Freighter::dock(std::weak_ptr<Port> port) {
    if(trackBase.getPosition().distance(port.lock()->getPosition()) <= 0.1){
        setStatus(Ship::Status::Docked);
        trackBase.setPort(port);
        trackBase.setSpeed(0);
        trackBase.setPosition(port.lock()->getPosition());
    }
}

void Freighter::decreaseGas() {
    Gas -= trackBase.getSpeed()*GAS_USE_PER_NM_FREIGHTER;
    if(Gas <=0){//if the ship doesn't have gas she change her status to dead in water
        setStatus(Ship::Status::DeadInTheWater);
        Gas = 0;
    }
}

void Freighter::printStatus() const {
    cout << "Freighter " << name << " at ";
    trackBase.getPosition().print();
    cout << " , fuel: " << Gas << "kl, resistance:" << Resistance << ", ";
    if(status == Ship::Status::MovingTo)
        printMoveWay();
    else if(status == Ship::Status::Stopped)
        cout << "Stopped";
    else if(status == Ship::Status::DeadInTheWater)
        cout << "Dead in the water";
    else
        cout << "Docked at " << trackBase.getPort().lock()->getPortName();
    cout << " ,Containers: " << Containers << endl;

    /*if(loadStatus == NotLoadOrUnload)
        cout << "no cargo destination\n";
    else if(loadStatus == Loading)
        cout << "moving to loading destination\n";
    else
        cout << "moving to unloading destination\n";*/

}

void Freighter::refuelAfterQue() {
    auto port  = trackBase.getPort().lock();
    if((port->getGasStoke()+Gas) <= MAX_GAS_FREIGHTER){
        Gas += port->getGasStoke();
        port->setGasStoke(0);
    }
    else{
        int x = MAX_GAS_FREIGHTER - Gas;
        Gas += x;
        port->setGasStoke(port->getGasStoke() - x);
    }
}

bool Freighter::existInMissionQue() {
    for(auto x : missionQue){
        if(x.first == trackBase.getPort().lock()->getPortName())
            return true;
    }
    return false;
}

