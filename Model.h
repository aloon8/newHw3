//

//

#ifndef EXERCISE3_MODEL_H
#define EXERCISE3_MODEL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "AbstractFactory.h"
#include "Ship.h"


class Model {
public:
    //void create(string shipName, TrackBase::MovingType type, const Point& pos, int resOatt, int rangeOcap = 0 );

    Model();

    ~Model(){}

    void go();

    void update();

    void addPort(const std::string portName,const Point& pos, const int GasStoke, const int produce);

    void addShip( const string& shipType ,const string& shipName , Point& pos, int resOatt, int rangeOcap = 0 );

    void printAllObjectsStatus();

    std::vector<shared_ptr<Ship>>::iterator findShip(const string& name);

    std::vector<shared_ptr<Port>>::iterator findPort(const string& name);

    /**    Getters & Setters   **/

    const vector<shared_ptr<Port>> &getPortVec() const;

    static Model& getInstance(); // Singleton

    int getTime() const;

    vector<vector<string>> &getVectorOfCommands();

    int getSizeOfPortVector(){return (int)portVec.size();}

    const vector<shared_ptr<Ship>> &getShipVec() const;

    const shared_ptr<AbstractFactory> &getShipFactory() const;

    void stopThisShip(const string& shipName);


private:
    std::vector<shared_ptr<Ship>> shipVec;

    std::vector<shared_ptr<Port>> portVec;

    std::shared_ptr<AbstractFactory> shipFactory;

    std::vector<std::vector<std::string>> vectorOfCommands;

    int time;
};



#endif //EXERCISE3_MODEL_H
