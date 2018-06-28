#include <iostream>
#include <memory>
#include "Ship.h"
#include "Cruiser.h"
#include "Freighter.h"

int main() {
    std::shared_ptr<Ship> cr1(new Freighter("alon",Point(2,2),50,50));
    cr1->printStatus();

    Point p(2,1);
    Point p1(30,50);
    std::shared_ptr<Port> port(new Port("nagoya",p1,500,20));
    std::shared_ptr<Port> port1(new Port("Jer",p,500,20));
    cr1->load_at(port);
    cr1->Moving(port,20);
    cr1->update();
    cr1->update();
    cr1->update();
    cr1->printStatus();
    cr1->Moving(port1,20);
    cr1->update();
    cr1->printStatus();
}