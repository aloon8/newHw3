//

//

#ifndef EXERCISE3_MODEL_H
#define EXERCISE3_MODEL_H

#include <iostream>
#include <vector>
#include <memory>
#include "AbstractFactory.h"

#include "Ship.h"


class Model {
public:
    //void create(string shipName, TrackBase::MovingType type, const Point& pos, int resOatt, int rangeOcap = 0 );

    Model();

    const vector<shared_ptr<Port>> &getPortVec() const;

    static Model& getInstance(); // Singleton

    void update();

    int getSizeOfPortVector(){return (int)portVec.size();}

    ~Model(){}


private:
    std::vector<shared_ptr<Ship>> shipVec;

    std::vector<shared_ptr<Port>> portVec;

    std::shared_ptr<AbstractFactory> shipFactory;

    int time;
};



#endif //EXERCISE3_MODEL_H
