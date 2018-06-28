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
    portVec.emplace_back(make_shared<Port>("Nagoya",p,1000000,1000));
    shipFactory = std::make_shared<ShipFactory>();
}

void Model::update() {
    time++; // incrementing time every update
    for (int i = 0; i < portVec.size(); ++i)
        portVec[i]->update();
    for (int i = 0; i < shipVec.size(); ++i)
        shipVec[i]->update();
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

const vector<shared_ptr<Ship>> &Model::getShipVec() const {
    return shipVec;
}

const shared_ptr<AbstractFactory> &Model::getShipFactory() const {
    return shipFactory;
}

std::vector<shared_ptr<Ship>>::iterator Model::findShip(string &name) {
    auto beg = shipVec.begin();
    auto end = shipVec.end();
    while(beg != end) {
        if((*beg)->getName() == name)
            return beg;
    }
    return beg;
}

vector<vector<string>> &Model::getVectorOfCommands() {
    return vectorOfCommands;
}

void Model::go() {
    for (int i = 0; i < attackVector.size(); ++i) {
        auto tmpVec = attackVector[i];
        //attack
    }
    attackVector.clear();
    for (int i = 0; i < vectorOfCommands.size(); ++i) {
        auto tmpVector = vectorOfCommands[i];

        if (tmpVector[0] == "go") {

        }else if (tmpVector[0] == "course"){

        }else if(tmpVector[0] == "position"){

        }else if(tmpVector[0] == "destination"){

        }else if(tmpVector[0] == "load_at"){

        }else if(tmpVector[0] == "unload_at"){

        }else if(tmpVector[0] == "dock_at"){

        }else if(tmpVector[0] == "refuel"){

        }else if(tmpVector[0] == "stop"){

        }


    }
    vectorOfCommands.clear();

}


