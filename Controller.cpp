//
// Created by raviv on 6/17/18.
//

#include "Controller.h"

using namespace std;

Controller::Controller(int argc, char **argv) {

}



int Controller::hashing(std::string name){
    int cnt = 0;
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    for (unsigned int i = 0; i < name.size(); ++i)
        cnt += name[i];
    return cnt;
}

void Controller::run() {
    std::string command, line,tmp, name, shipType;
    Point point;
    double x,y;
    int resOatt, rangeOcap;
    std::vector<string> inputStringVector;

    typedef  enum {    DEFAULT = 741, SIZE = 443, ZOOM = 453, PAN = 319, SHOW = 449, STATUS = 676, GO = 214,
        CREATE = 628, COURSE = 657, POSITION = 885, DESTINATION = 1186, LOAD_AT = 724, UNLOAD_AT = 951, DOCK_AT = 725, ATTACK = 632, REFUEL = 643, STOP = 454 } InputCommand;

    try{
        while(true){
            line = "";
            cin >> line;
            stringstream ss(line);
            while(ss >> tmp) // inserting all the other arguments into a string vector
                inputStringVector.emplace_back(tmp);
            switch(hashing(inputStringVector[0])) {
                case InputCommand::DEFAULT:
                        break;


                    case InputCommand::SIZE:
                        break;


                    case InputCommand::ZOOM:
                        break;


                    case InputCommand::PAN:
                        break;


                    case InputCommand::SHOW:
                        break;


                    case InputCommand::STATUS:
                    if(inputStringVector[0] != "status")
                        throw MyExceptions::InvalidInput("Command not found");
                    Model::getInstance().printAllObjectsStatus();
                         break;


                    case InputCommand::GO:
                    if(inputStringVector[0] != "go")
                        throw MyExceptions::InvalidInput("Command not found");
                    Model::getInstance().go();
                        break;




                    case InputCommand::CREATE:
                    if(inputStringVector[0] != "create")
                        throw MyExceptions::InvalidInput("Command not found");

                    if(inputStringVector.size() < 5 || inputStringVector.size() > 6)
                        throw MyExceptions::InvalidArgument("Create needs 5 or 6 arguments");

                    if(Model::getInstance().findShip(inputStringVector[1]) != Model::getInstance().getShipVec().end()) // checks if the ship already exists
                        throw MyExceptions::InvalidInput("Ship already exists");

                    if(inputStringVector[2] != "Cruiser" && inputStringVector[2] != "Freighter" && inputStringVector[2] != "Patrol_boat")
                        throw MyExceptions::InvalidInput("No such type of ship");

                    inputStringVector[3].erase(inputStringVector[3].begin(),inputStringVector[3].begin() + 1); // erasing '(' from double
                    inputStringVector[4].pop_back(); // erasing ')'
                    if(!isNumber(inputStringVector[3]) || !isNumber(inputStringVector[4]) || !isNumber(inputStringVector[5]))
                        throw MyExceptions::ParsingError("Cannot parse a non-digit character to a double or an int");

                    if(inputStringVector[2] != "Patrol_boat" && !isNumber(inputStringVector[6]))
                        throw MyExceptions::ParsingError("Cannot parse a non-digit character to a double or an int");

                    point.x = std::stod(inputStringVector[3]);
                    point.y = std::stod(inputStringVector[4]);
                    resOatt = std::stoi(inputStringVector[5]);//throws invalid_argument of c++ std exceptions if fails

                    if(name != "Patrol_boat"){
                        rangeOcap = std::stoi(inputStringVector[6]);
                        Model::getInstance().addShip(inputStringVector[2],inputStringVector[1],point,resOatt,rangeOcap);
                    }else
                        Model::getInstance().addShip(inputStringVector[2],inputStringVector[1],point,resOatt);
                    break;


                    case InputCommand::COURSE:
                        break;


                    case InputCommand::POSITION:
                        break;


                    case InputCommand::DESTINATION:
                        break;


                    case InputCommand::LOAD_AT:
                        break;


                    case InputCommand::UNLOAD_AT:
                        break;


                    case InputCommand::DOCK_AT:
                        break;


                    case InputCommand::ATTACK:
                        break;


                    case InputCommand::REFUEL:
                        break;


                    case InputCommand::STOP:
                        break;
                default:
                    cout << "Command not found\n";

                } // switch
            } //while
        }catch (MyExceptions::InvalidInput& ii) {
            ii.print();
        }catch (MyExceptions::InvalidArgument& pa){
            pa.print();
        }catch(MyExceptions::ParsingError& pe){
            pe.print();
        }

    }// function run()

