//
// Created by raviv on 6/17/18.
//

#ifndef EXERCISE3_TRACKBASE_H
#define EXERCISE3_TRACKBASE_H


#include <memory>
#include "Port.h"


class TrackBase {
public:
    typedef enum {Angle,ByPort,PointDest} MovingType;

    TrackBase(const Point &p);

    const Point &getPosition() const;

    void setPosition(const Point &position);

    const Point &getDestination() const;

    void setDestination(const Point &destination);

    MovingType getMovingWay() const;

    void setMovingWay(MovingType movingWay);

    double getAngle() const;

    void setAngle(double angle);

    const weak_ptr<Port> &getPort() const;

    void setPort(const weak_ptr<Port> &port);

    int getSpeed() const;

    void setSpeed(int speed);

private:

    Point position,destination;

    MovingType movingWay;

    double angle;

    weak_ptr<class Port> port;

    int speed;
};


#endif //EXERCISE3_TRACKBASE_H
