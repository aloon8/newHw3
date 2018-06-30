//
// Created by Admin on 19/06/2018.
//

#ifndef EXERCISE3_VIEW_H
#define EXERCISE3_VIEW_H

#include "Model.h"


class View {

public:

    View(Model& mo) : model(mo), size(15), scale(5.0), axis(Point(-20.00,-20.00)) {}

    void defaultParam();

    void initObjectView();

    void show();

    string BullsEye(const Point& current);

    void addObjectView(const Point& p , const string& str);

    string printSpacesForNumber(int num);

    string printAtStart(int num);


private:

    class objectView{
    public:
        objectView(Point p, string str) : point(p), twoChars(str){}

        Point point;

        std:: string twoChars;

    };

    void sortObjectVector();

    std::vector<objectView> objectsVec;

    Model& model;

    int size;

    double scale;

    Point axis;

};


#endif //EXERCISE3_VIEW_H
