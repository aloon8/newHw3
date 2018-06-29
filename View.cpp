//
// Created by Admin on 19/06/2018.
//

#include "View.h"

void View::defaultParam() {
    size = 25;
    scale = 2.0;
}

void View::initObjectView() {
    for (int i = 0; i < Model::getInstance().getPortVec().size(); ++i) {
        auto tmpPort = Model::getInstance().getPortVec()[i];
        objectsVec.emplace_back(objectView(tmpPort->getPosition(),tmpPort->getPortName().substr(0,2)));
    }
}

void View::show() {
    sortObjectVector();
    string empty = ". ";
    int idx = 0, space;


}

void View::addObjectView(const Point &p, const string& str) {
    objectsVec.emplace_back(objectView(p,str));
}

void View::sortObjectVector() {
    std::sort(objectsVec.begin(), objectsVec.end(), [](objectView a, objectView b) -> bool {
        if (a.point.y == b.point.y)
            return a.point.x > b.point.x;
        else
            return a.point.y > b.point.y;
    });
}

string View::BullsEye(const Point &current) {
    string empty = ". ";
    auto obj = std::find_if(objectsVec.begin(),objectsVec.end(),[&current] (objectView a) ->bool {return (a.point.x == current.x && a.point.y == current.y); });
    if(obj == objectsVec.end())
        return empty;
    else
        return obj->twoChars;
}

int View::spaces(int spc) {
    int cnt = 0;

    if(spc == 0)
        return 1;
    if( spc < 0 ) {
        spc = spc * -1;
        cnt++;
    }
    while(spc){
        cnt++;
        spc = spc/10;
    }
    return cnt;


}
