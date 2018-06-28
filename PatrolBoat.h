//
// Created by Admin on 19/06/2018.
//

#ifndef EXERCISE3_PATROLBOAT_H
#define EXERCISE3_PATROLBOAT_H

#include <ostream>
#include "Ship.h"
#include "Model.h"



class PatrolBoat : public Ship{
public:

    PatrolBoat(const std::string& shipName, const Point& pos, int Resistance);

    virtual void Moving(weak_ptr<class Port> port, int speed);

    virtual void update();

    virtual void printStatus() const;

    const vector<shared_ptr<Ship>>& getVecShip()const{ return Model::getInstance().getShipVec();}

    void docked();

    virtual void refuelAfterQue();

    std::weak_ptr<Port> givesTheCloserPort();

    int givesIndexOfPort(std::weak_ptr<Port> port);

    virtual TypeIdShip getTypeName(){ return myType;}

    static const int MAX_SPEED_PATROL = 15;
    static const int MAX_GAS_PATROL = 500000;
    static const int GAS_USE_PER_NM_PATROL = 2000;

    int getResistance() const;

    void setResistance(int Resistance);

private:
    int Resistance,index,numOfMoves,Gas;

    TypeIdShip myType;

    vector<bool> visitedPorts;

    //bool existInQueueGas;

    //functions
    void decreaseGas();
};


#endif //EXERCISE3_PATROLBOAT_H
