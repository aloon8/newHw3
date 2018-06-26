//
// Created by raviv on 6/17/18.
//

#include "Controller.h"

using namespace std;


int Controller::hashing(std::string name){
    int cnt = 0;
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    for (unsigned int i = 0; i < name.size(); ++i)
        cnt += name[i];
    return cnt;
}

void Controller::run() {
    std::string command, line,tmp, name, shipType;
    double x,y;
    int resOatt, rangeOcap;
    std::vector<string> inputStringVector;

    enum {    DEFAULT = 741, SIZE = 443, ZOOM = 453, PAN = 319, SHOW = 449, STATUS = 676, GO = 214,
        CREATE = 628, COURSE = 657, POSITION = 885, DESTINATION = 1186, LOAD_AT = 724, UNLOAD_AT = 951, DOCK_AT = 725, ATTACK = 632, REFUEL = 643, STOP = 454 };

    try{
        while(true){
            cin >> line;
            stringstream ss(line);
            line = "";
            ss >> command; // inserting the first word, command int command string
            while(ss >> tmp) // inserting all the other arguments into a string vector
                inputStringVector.emplace_back(tmp);
            switch(hashing(command)) {
                    case DEFAULT:
                        break;


                    case SIZE:
                        break;


                    case ZOOM:
                        break;


                    case PAN:
                        break;


                    case SHOW:
                        break;


                    case STATUS:
                    if(command != "status")
                        throw MyExceptions::InvalidInput("Command not found");
                    Model::getInstance().printAllObjectsStatus();
                         break;


                    case GO:
                    if(command != "go")
                        throw MyExceptions::InvalidInput("Command not found");
                    Model::getInstance().update();
                        break;




                    case CREATE:
                    if(command != "create")
                        throw MyExceptions::InvalidInput("Command not found");
                    if(inputStringVector.size() < 5 || inputStringVector.size() > 6)
                        throw MyExceptions::InvalidArgument("Create needs 5 or 6 arguments");
                    ss >> name;
                    if(Model::getInstance().findShip(name) == Model::getInstance().getShipVec().end()) // checks if the ship a lready exists
                        throw MyExceptions::InvalidInput("Ship already exists");

                    if(inputStringVector[2] != "Cruiser" && inputStringVector[2] != "Freighter" && inputStringVector[2] != "Patrol_boat")
                        throw MyExceptions::InvalidInput("No such type of ship");
                    inputStringVector[3].erase(inputStringVector[3].begin(),inputStringVector[3].begin() + 1); // erasing '(' from double
                    inputStringVector[4].pop_back();
                    x = std::stod(inputStringVector[3]); //throws invalid_argument of c++ if fails
                    y = std::stod(inputStringVector[4]); //throws invalid_argument of c++ if fails
                    Point p(x,y);
                    resOatt = std::stoi(inputStringVector[5]);
                    if(name != "Patrol_boat"){
                        rangeOcap = std::stoi(inputStringVector[6]);
                        Model::getInstance().getShipFactory()->getShip(name,inputStringVector[2],p,resOatt,rangeOcap);
                    }else
                        Model::getInstance().getShipFactory()->getShip(name,inputStringVector[2],p,resOatt);


                        break;



                    case COURSE:
                        break;


                    case POSITION:
                        break;


                    case DESTINATION:
                        break;


                    case LOAD_AT:
                        break;


                    case UNLOAD_AT:
                        break;


                    case DOCK_AT:
                        break;


                    case ATTACK:
                        break;


                    case REFUEL:
                        break;


                    case STOP:
                        break;
                default:
                    cout << "Command not found\n";

                } // switch
            } //while
        }catch (MyExceptions::InvalidInput& ii) {
            ii.print();
        }catch (MyExceptions::InvalidArgument& pa){
            pa.print();
        }catch(std::invalid_argument& e) {
            cout << "Cannot parse a string that is not a number to a double\n"; // occurs when trying to parse a string into a double but fails (in function create)
        }

    } // function run()

