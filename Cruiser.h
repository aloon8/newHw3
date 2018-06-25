//
// Created by raviv on 6/17/18.
//

#ifndef EXERCISE3_CRUISER_H
#define EXERCISE3_CRUISER_H

#include <iostream>
#include "Ship.h"

class Cruiser : public Ship{

public:
    Cruiser(std::string shipName, const Point& pos, int resOatt, int rangeOcap );

    static const int MAX_SPEED_Cruiser = 75;

    virtual TypeIdShip getTypeName(){ return myType;}

    virtual void Moving(Point& point, int speed);

    virtual void Moving(double angle, int speed);

    virtual void attack(std::weak_ptr<Ship> ship);

    void update() {}

    void printStatus() const;
private:
    int Force_of_attack, range;

    TypeIdShip myType;
};


#endif //EXERCISE3_CRUISER_H
