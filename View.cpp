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
    //sortObjectVector();
    const int NumOfTimesToPrintNumber = 3;
    string empty = ". ";

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if(x == 0) {
                if( (int)(((size-y)*scale) + axis.y ) % size == 0) {
                    double num =  (((size - 1) - y) * scale) + axis.y;
                    cout << printAtStart((int)num) << num << " ";
                }else
                    cout << "     "; // 5 spaces
            }
            cout << BullsEye(Point(axis.x + (x*scale),(axis.y + (size-1 -y) * scale))); // printing the current point in the map or ". "
        }
        cout << endl;
    }
    cout << "   ";
    for (int x = 0; x < size ; ++x) {
        if( x % NumOfTimesToPrintNumber == 0)
            cout << axis.x + x*scale << "    ";
    }

    cout << endl;

}

void View::addObjectView(const Point &p, const string& str) {
    objectsVec.emplace_back(objectView(p,str));
}

void View::sortObjectVector() { // sorting by Y
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

string View::printAtStart(int num) {

    string str = "";
    int count = num < 0 ? 1 : 0;

    while(num){
        num /= 10;
        count++;
    }
    int tmp = 4 - count;

    while(tmp--){
        str += " ";
    }
    return str;
}
