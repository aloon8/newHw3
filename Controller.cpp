//
// Created by raviv on 6/17/18.
//

#include "Controller.h"

using namespace std;


int Controller::hashing(const std::string& name){
    int cnt = 0;
    //std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    for (unsigned int i = 0; i < name.size(); ++i)
        cnt += name[i];
    return cnt;
}

void Controller::run() {
    std::string command = "";

    enum {    DEFAULT = 741, SIZE = 443, ZOOM = 453, PAN = 319, SHOW = 449, STATUS = 676, GO = 214,
        CREATE = 628, COURSE = 657, POSITION = 885, DESTINATION = 1186, LOAD_AT = 724, UNLOAD_AT = 951, DOCK_AT = 725, ATTACK = 632, REFUEL = 643, STOP = 454 };

    try{
        while(command != "exit"){
                cin >> command;
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
                            if(command != "status"){
                                throw MyExceptions::InvalidCommand("Command not found");
                            }
                         Model::getInstance().printAllObjectsStatus();
                             break;


                        case GO:
                        Model::getInstance().update();
                            break;


                        case CREATE:
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
            }catch (MyExceptions::InvalidCommand& ic) {
            ic.print();
            }

    } // function run()

