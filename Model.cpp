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
        beg++;
    }
    return beg;
}

std::vector<shared_ptr<Port>>::iterator Model::findPort(const string &name) {
    auto beg = portVec.begin();
    auto end = portVec.end();
    while(beg != end) {
        if((*beg)->getPortName() == name)
            return beg;
        beg++;
    }
    return beg;
}

vector<vector<string>> &Model::getVectorOfCommands() {
    return vectorOfCommands;
}

void Model::go() {
    int speed;
    double angle;
    Point point;


    for (auto Command : vectorOfCommands) {

        if (Command[1] == "course"){
            (*findShip(Command[0]))->Moving(std::stod(Command[2]),std::stoi(Command[1]));
        }else if(Command[1] == "position"){
            point.x = std::stod(Command[2]);
            point.y = std::stod(Command[3]);
            (*findShip(Command[0]))->Moving(point,std::stoi(Command[4]));
        }else if(Command[1] == "destination"){
//            (*findShip(Command[0]))->Moving((*findPort(Command[3])),std::stoi(Command[3]));
            auto tmpShip = (*findShip(Command[0]));
            cout << "aFter Find Ship\n";
            auto tmpPort = (*findPort(Command[2]));
            cout << "after Find Port\n";
            tmpShip->Moving(tmpPort,std::stoi(Command[3]));

        }else if(Command[1] == "load_at"){
            (*findShip(Command[0]))->load_at((*findPort(Command[2])));
        }else if(Command[1] == "unload_at"){
            (*findShip(Command[0]))->unload_at((*findPort(Command[2])),std::stoi(Command[3]));
        }else if(Command[1] == "dock_at"){
            (*findShip(Command[0]))->dock((*findPort(Command[2])));
        }else if(Command[1] == "refuel"){
            (*findShip(Command[0]))->refuel();
        }else if(Command[1] == "stop"){
//            (*findShip(Command[0]))->
        }else if(Command[1] == "attack"){
            (*findShip(Command[0]))->attack((*findShip(Command[2])));
        }

    }
    vectorOfCommands.clear();
    update();
}


