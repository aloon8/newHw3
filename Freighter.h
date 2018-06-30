//
// Created by raviv on 6/17/18.
//

#ifndef EXERCISE3_FREIGHTER_H
#define EXERCISE3_FREIGHTER_H


#include "Ship.h"

class Freighter : public Ship {
public:

    //typedef enum {NotLoadOrUnload, Loading, Unloading} LoadingStatus;

    Freighter(std::string shipName, const Point& pos,int Resistance,int Containers);

    virtual void update();

    virtual void printStatus() const;

    virtual void stop();

    virtual TypeIdShip getTypeName(){ return myType;}

    virtual void Moving(weak_ptr<class Port> port, int speed);

    virtual void Moving(Point &point, int speed);

    virtual void Moving(double angle, int speed);

    void docked();//when the ship is docked

    void dock(std::weak_ptr<Port> port);//when the ship in radius 0.1 from specific port

    virtual void load_at(std::weak_ptr<Port> port);

    void unload_at(std::weak_ptr<Port> port, int containers);


    static const int MAX_GAS_FREIGHTER = 500000; // max gas that a freighter can contain

    virtual void refuelAfterQue();


    int getResistance() const;

    void setResistance(int Resistance);

    int getContainers() const;

    void setContainers(int Containers);

    static const int GAS_USE_PER_NM_FREIGHTER = 1000; // use of gas per nm

private:

    int Resistance, Containers;

    double Gas;

    TypeIdShip myType;

    const int maxContainers;

    vector<std::pair<std::string,std::string>> missionQue;

    //function

    bool existInMissionQue();

    void decreaseGas();
};


#endif //EXERCISE3_FREIGHTER_H
