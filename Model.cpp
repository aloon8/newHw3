//
// Created by Admin on 19/06/2018.
//

#include "Model.h"


const vector<shared_ptr<Port>> &Model::getPortVec() const {
    return portVec;
}

Model& Model::getInstance() {
    static Model m;
    return m;
}
