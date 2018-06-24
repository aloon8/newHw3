//
// Created by raviv on 6/17/18.
//

#include "Cruiser.h"

Cruiser::Cruiser(std::string shipName, const Point& pos, int resOatt, int rangeOcap) : Ship(shipName,pos)
, Force_of_attack(resOatt), range(rangeOcap),myType(CR){}

void Cruiser::Moving(Point& point, int speed){
    trackBase.setMovingWay(TrackBase::PointDest);
    trackBase.setDestination(point);
    trackBase.setSpeed(speed);
}

void Cruiser::Moving(double angle, int speed){
    trackBase.setMovingWay(TrackBase::Angle);
    trackBase.setAngle(angle);
    trackBase.setSpeed(speed);
}

void Cruiser::attack(std::weak_ptr<Ship> ship){
    if(range > trackBase.getPosition().distance(ship.lock()->getTrackBase().getPosition())){
        //throw exception
    }
    ship.lock()->setStatus(Stopped);

}