//
// Created by Admin on 19/06/2018.
//

#include "Model.h"
#include "ShipFactory.h"


const vector<shared_ptr<Port>> &Model::getPortVec() const {
    return portVec;
}

Model& Model::getInstance() {
    static Model m;
    return m;
}

Model::Model() : time(0) {
    Point p(50,5);
    portVec.emplace_back(new Port("Nagoya",p,1000000,1000));
    shipFactory = std::make_shared<ShipFactory>();
}

void Model::update() {
    time++; // incrementing time every update
    for (int i = 0; i < portVec.size(); ++i)
        portVec[i]->update();
    for (int i = 0; i < shipVec.size(); ++i) {
        shipVec[i]->update();
    }
}

void Model::addPort(const string portName, const Point &pos, const int GasStoke, const int produce) {
    portVec.emplace_back(new Port(portName,pos,GasStoke,produce));
}

void Model::addShip(const string &shipType, const string &shipName, Point &pos, int resOatt, int rangeOcap) {
    shipVec.emplace_back(shipFactory->getShip(shipType,shipName,pos,resOatt,rangeOcap));
}

int Model::getTime() const {
    return time;
}

void Model::printAllObjectsStatus() {
    for (auto tmpPort : portVec)
        tmpPort->printStatus();
    for(auto tmpShip : shipVec)
        tmpShip->printStatus();
}


