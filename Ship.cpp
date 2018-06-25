//
// Created by Admin on 19/06/2018.
//

#include "Ship.h"

Ship::Ship(const string& name,const Point& point, const Status& status ) :
        name(name), trackBase(TrackBase(point)), status(status){}

const TrackBase &Ship::getTrackBase() const {
    return trackBase;
}

Ship::Status Ship::getStatus() const {
    return status;
}

void Ship::setStatus(Ship::Status status) {
    Ship::status = status;
}

void Ship::printMoveWay() const {
    if(trackBase.getMovingWay() == TrackBase::MovingType::PointDest){
        cout << "Moving to ";
        trackBase.getDestination().print();
        cout << " on course";
    }
    else if(trackBase.getMovingWay() == TrackBase::MovingType::ByPort){
        cout << "Moving to " << trackBase.getPort().lock()->getPortName()<< " on course";
    }
    else if(trackBase.getMovingWay() == TrackBase::MovingType::Angle){
        cout << "Moving on course " << trackBase.getAngle();
    }
}

