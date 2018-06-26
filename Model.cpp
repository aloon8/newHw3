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
    for (int i = 0; i < portVec.size(); ++i)
        portVec[i]->update();
    for (int i = 0; i < shipVec.size(); ++i) {
        shipVec[i]->update();
    }
}


