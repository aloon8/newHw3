//
// Created by raviv on 6/17/18.
//

#include "Freighter.h"

//Freighter::MAX_GAS = 500000;



Freighter::Freighter(std::string shipName, const Point& pos,int Resistance,int Containers) : Ship(shipName, pos)
        , Resistance(Resistance), Containers(Containers), Gas(MAX_GAS_FREIGHTER), myType(FR){}