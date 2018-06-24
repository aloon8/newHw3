//
// Created by Admin on 19/06/2018.
//

#include "PatrolBoat.h"

PatrolBoat::PatrolBoat(const std::string& shipName, const Point& pos, int Resistance) : Ship(shipName, pos), Resistance(Resistance),myType(PB){}

