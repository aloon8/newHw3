//
// Created by raviv on 6/17/18.
//

#ifndef EXERCISE3_SHIP_H
#define EXERCISE3_SHIP_H

#include <iostream>
#include <memory>
#include <iomanip>
#include "TrackBase.h"



class Ship {
public:
    typedef enum{Stopped, Docked,DeadInTheWater, MovingTo} Status;

    typedef enum{PB, FR, CR} TypeIdShip;

    Ship(const std::string& name,const Point& point, const Status& status = Status::Stopped );

    friend bool operator==(std::shared_ptr<Ship> s1, const Ship& s2){return s1->name == s2.name;}
    //friend bool operator==(const Ship& s1 , std::weak_ptr<Ship> s2)const {return s1.name == s2.lock()->name;}



    virtual TypeIdShip getTypeName()=0;
//    void Stop();
//
//    virtual void Dock(weak_ptr<class Port> port);
//
//    virtual void Unload(int numOfContainersToUnload);
//
//    virtual void load();
//
//    virtual void DeadInWater();
//
      virtual void Moving(weak_ptr<class Port> port, int speed){}
//
      virtual void Moving(Point& point, int speed){}

      virtual void Moving(double angle, int speed){}

      virtual void attack(std::weak_ptr<Ship> ship){}
//
//    virtual void reFuel();

    inline std::string getName(){return name;}

    virtual void update() = 0;

    virtual void printStatus() const = 0;

    void printMoveWay()const;

    const TrackBase &getTrackBase() const;

    Status getStatus() const;

    void setStatus(Status status);

protected:

    std::string name;

    TrackBase trackBase;

    Status status;

};


#endif //EXERCISE3_SHIP_H


