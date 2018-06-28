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
    for (int i = 0; i < shipVec.size(); ++i)
        shipVec[i]->update();
    for (int i = 0; i < portVec.size(); ++i)
        portVec[i]->update();
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

std::vector<shared_ptr<Ship>>::iterator Model::findShip(const string &name) {
    auto beg = shipVec.begin();
    auto end = shipVec.end();
    while(beg != end) {
        if((*beg)->getName() == name)
            return beg;
    }
    return beg;
}

std::vector<shared_ptr<Port>>::iterator Model::findPort(const string &name) {
    auto beg = portVec.begin();
    auto end = portVec.end();
    while(beg != end) {
        if((*beg)->getPortName() == name)
            return beg;
    }
    return beg;
}

vector<vector<string>> &Model::getVectorOfCommands() {
    return vectorOfCommands;
}

void Model::go() {
    int speed;
    double angle;


    for (auto Command : vectorOfCommands) {

        if (Command[1] == "course"){
            auto tmpShip = findShip(Command[0]);
            (*tmpShip)
        }else if(Command[1] == "position"){

        }else if(Command[1] == "destination"){

        }else if(Command[1] == "load_at"){

        }else if(Command[1] == "unload_at"){

        }else if(Command[1] == "dock_at"){

        }else if(Command[1] == "refuel"){

        }else if(Command[1] == "stop"){

        }else if(Command[1] == "attack"){

        }

    }
    vectorOfCommands.clear();
    update();
}


