//
// Created by raviv on 6/17/18.
//

#ifndef EXERCISE3_FREIGHTER_H
#define EXERCISE3_FREIGHTER_H


#include "Ship.h"

class Freighter : public Ship {
public:

    typedef enum {NotLoadOrUnload, Loading, Unloading} LoadingStatus;

    Freighter(std::string shipName, const Point& pos,int Resistance,int Containers);

    void Dock(weak_ptr<Port> port);

    virtual void update(){}

    virtual void printStatus() const;

    virtual TypeIdShip getTypeName(){ return myType;}


    static const int MAX_GAS_FREIGHTER = 500000; // max gas that a freighter can contain

    static const int MAX_SPEED_FREIGHTER = 40; // max speed of freighter

    int getResistance() const;

    void setResistance(int Resistance);

    int getContainers() const;

    void setContainers(int Containers);

    int getGas() const;

    void setGas(int Gas);

    static const int GAS_USE_PER_NM_FREIGHTER = 1000; // use of gas per nm


private:
    int Resistance, Containers, Gas;

    TypeIdShip myType;

    LoadingStatus loadStatus;

};


#endif //EXERCISE3_FREIGHTER_H
