//
// Created by Admin on 24/06/2018.
//

#ifndef EXERCISE3_ABSTRACTFACTORY_H
#define EXERCISE3_ABSTRACTFACTORY_H

#include <iostream>
#include <memory>
class AbstractFactory {
    virtual std::shared_ptr<class Ship> getShip() = 0;
};


#endif //EXERCISE3_ABSTRACTFACTORY_H
