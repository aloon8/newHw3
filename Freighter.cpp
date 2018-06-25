//
// Created by raviv on 6/17/18.
//

#include "Freighter.h"

//Freighter::MAX_GAS = 500000;



Freighter::Freighter(std::string shipName, const Point& pos,int Resistance,int Containers) : Ship(shipName, pos)
        , Resistance(Resistance), Containers(Containers), Gas(MAX_GAS_FREIGHTER), myType(FR), loadSatus(LoadingStatus::NotLoadOrUnload){}

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
    cout << " ,Containers: " << Containers;

    if(loadStatus == NotLoadOrUnload)
        cout << "no cargo destination\n";
    else if(loadStatus == Loading)
        cout << "moving to loading destination\n";
    else
        cout << "moving to unloading destination\n";

}
