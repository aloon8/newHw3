#include <iostream>
#include <memory>
#include "Ship.h"
#include "Cruiser.h"

int main() {
    std::shared_ptr<Ship> cr1(new Cruiser("alon", Point(2.,2.),50,20));
    cr1->printStatus();
    Point p(2,1);
    Point p1(6,5);
    std::shared_ptr<Port> port(new Port("nagoya",p1,500,20));
    cr1->Moving(20,20);
    cr1->printStatus();
}