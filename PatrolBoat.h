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

    void update(){}

    void printStatus() const {}

    void get(){ Model::getInstance().getPortVec();}

    virtual TypeIdShip getTypeName(){ return myType;}

    static const int MAX_SPEED_PATROL = 15;
    static const int MAX_GAS_PATROL = 500000;
    static const int GAS_USE_PER_NM_PATROL = 2000;

private:

    int Resistance,index,numOfMoves;

    TypeIdShip myType;

    bool visitedPorts[];


};


#endif //EXERCISE3_PATROLBOAT_H
