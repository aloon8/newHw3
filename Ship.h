//
// Created by raviv on 6/17/18.
//

#ifndef EXERCISE3_SHIP_H
#define EXERCISE3_SHIP_H

#include <iostream>
#include <memory>
#include <iomanip>
#include "TrackBase.h"
#include "MyExceptions.h"



class Ship {
public:
    typedef enum{Stopped, Docked,DeadInTheWater, MovingTo} Status;

    typedef enum{PB, FR, CR} TypeIdShip;

    Ship(const std::string& name,const Point& point, const Status& status = Status::Stopped );

    friend bool operator==(std::shared_ptr<Ship> s1, const Ship& s2){return s1->name == s2.name;}
    friend bool operator==(std::shared_ptr<Ship> s1 , std::weak_ptr<Ship> s2) {return s1->name == s2.lock()->name;}



    virtual TypeIdShip getTypeName()=0;

//    void Stop();

    virtual void load_at(std::weak_ptr<Port> port){}

    virtual void Moving(weak_ptr<Port> port, int speed){}

    virtual void unload_at(std::weak_ptr<Port> port, int containers){}

    virtual void dock(std::weak_ptr<Port> port){}

    virtual void Moving(Point& point, int speed);

    virtual void Moving(double angle, int speed);

    virtual void stepOnWater();

    virtual void attack(std::weak_ptr<Ship> ship){}

    virtual void refuelAfterQue(){}

    void refuel();

    inline std::string getName(){return name;}

    virtual void update() = 0;

    virtual void printStatus() const = 0;

    void printMoveWay()const;

    const TrackBase &getTrackBase() const;

    Status getStatus() const;

    void setStatus(Status status);

    virtual int getNumOfMoves() const{}
protected:

    std::string name;

    TrackBase trackBase;

    Status status;

    bool existInQueueGas;

};


#endif //EXERCISE3_SHIP_H


