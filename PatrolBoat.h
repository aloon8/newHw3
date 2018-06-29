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

    virtual void Moving(Point &point, int speed);

    virtual void Moving(double angle, int speed);

    virtual void update();

    virtual void printStatus() const;

    const vector<shared_ptr<Ship>>& getVecShip()const{ return Model::getInstance().getShipVec();}

    void docked();

    virtual void refuelAfterQue();

    std::weak_ptr<Port> givesTheCloserPort();

    int givesIndexOfPort(std::weak_ptr<Port> port);

    std::weak_ptr<Port> givesPortByIndex();

    virtual TypeIdShip getTypeName(){ return myType;}

    static const int MAX_GAS_PATROL = 900000;
    static const int GAS_USE_PER_NM_PATROL = 2000;

    int getResistance() const;

    void setResistance(int Resistance);

    virtual int getNumOfMoves() const;

    void setNumOfMoves(int numOfMoves);

private:
    int Resistance,index,numOfMoves,Gas;

    TypeIdShip myType;

    vector<bool> visitedPorts;

    int indexOfFirstPort;

    //functions
    void decreaseGas();
};


#endif //EXERCISE3_PATROLBOAT_H
