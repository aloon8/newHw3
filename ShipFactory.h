//
// Created by Admin on 24/06/2018.
//

#ifndef EXERCISE3_SHIPFACTORY_H
#define EXERCISE3_SHIPFACTORY_H

#include <memory>
#include "AbstractFactory.h"
#include "PatrolBoat.h"
#include "Cruiser.h"
#include "Freighter.h"



class ShipFactory : public AbstractFactory{

    std::shared_ptr<Ship> getShip( const string& shipType ,const string& shipName const, Point& pos, int resOatt, int rangeOcap = 0 ){
        shared_ptr<Ship> nwShip(nullptr);
        if(shipType == "Cruiser"){
            nwShip = std::shared_ptr<Ship>(new Cruiser(shipName,pos,resOatt,rangeOcap));
        }
        else if(shipType == "Freighter"){
            nwShip = std::shared_ptr<Ship>(new Freighter(shipName, pos, resOatt, rangeOcap));
        }
        else if(shipType == "PatrolBoat"){
            nwShip = std::shared_ptr<Ship>(new PatrolBoat(shipName, pos, resOatt));
        }
        //throw exception
        return nwShip;
    }
};


#endif //EXERCISE3_SHIPFACTORY_H
