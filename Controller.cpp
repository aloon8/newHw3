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
    std::string  line,tmp, hashMe;
    const int MAX_SHIP_NAME = 12;
    shared_ptr<Ship> tmpShip;
    Point point;
    int resOatt, rangeOcap,speed;
    bool inLoop = true;
    std::vector<string> inputStringVector;

    typedef  enum {    DEFAULT = 741, SIZE = 443, ZOOM = 453, PAN = 319, SHOW = 449, STATUS = 676, GO = 214, CREATE = 628, COURSE = 657, POSITION = 885,
        DESTINATION = 1186, LOAD_AT = 724, UNLOAD_AT = 951, DOCK_AT = 725, ATTACK = 632, REFUEL = 643, STOP = 454, EXIT = 442 } InputCommand;

    try{
        while(inLoop){
            line = "";
            cin >> line;
            stringstream ss(line);
            inputStringVector.clear();
            while(ss >> tmp) // inserting all the other arguments into a string vector
                inputStringVector.emplace_back(tmp);

            //because commands are the first or second word in the string, I'm checking if the first word is a ship and if not it's a command
            hashMe = Model::getInstance().findShip(inputStringVector[0]) == Model::getInstance().getShipVec().end() ? inputStringVector[1] : inputStringVector[0];

                switch(hashing(hashMe)) {
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
                        if(inputStringVector[1].size() > MAX_SHIP_NAME)
                            throw MyExceptions::InvalidInput("Ship name can be maximum 12 characters");

                        if(inputStringVector[2] != "Cruiser" && inputStringVector[2] != "Freighter" && inputStringVector[2] != "Patrol_boat")
                            throw MyExceptions::InvalidInput("No such type of ship");

                        inputStringVector[3].erase(inputStringVector[3].begin(),inputStringVector[3].begin() + 1); // erasing '(' from double
                        if(inputStringVector[3][inputStringVector[3].size() - 1] == ',')
                            inputStringVector[3].pop_back();
                        inputStringVector[4].pop_back(); // erasing ')'
                        if(!isNumber(inputStringVector[3]) || !isNumber(inputStringVector[4]) || !isNumber(inputStringVector[5]))
                            throw MyExceptions::ParsingError("Cannot parse a non-digit character to a double or an int");

                        if(inputStringVector[2] != "Patrol_boat" && !isNumber(inputStringVector[6]))
                            throw MyExceptions::ParsingError("Cannot parse a non-digit character to a double or an int");

                        point.x = std::stod(inputStringVector[3]);
                        point.y = std::stod(inputStringVector[4]);
                        resOatt = std::stoi(inputStringVector[5]);//throws invalid_argument of c++ std exceptions if fails

                        if(inputStringVector[2] != "Patrol_boat"){
                            rangeOcap = std::stoi(inputStringVector[6]);
                            Model::getInstance().addShip(inputStringVector[2],inputStringVector[1],point,resOatt,rangeOcap);
                        }else {
                            Model::getInstance().addShip(inputStringVector[2], inputStringVector[1], point, resOatt);
                        }
                         break;




                    case InputCommand::COURSE:
                        if(inputStringVector[1] != "course") // checking command validation
                            throw MyExceptions::InvalidInput("Command not found");
                        if(inputStringVector.size() != 4) // exactly 4 arguments
                            throw MyExceptions::InvalidArgument("Course needs 4 arguments");
                        if(Model::getInstance().findShip(inputStringVector[0]) == Model::getInstance().getShipVec().end()) // checks if the ship already exists
                            throw MyExceptions::InvalidInput("Ship doesn't exist");

                        tmpShip = (*Model::getInstance().findShip(inputStringVector[0]));
                        if(!isNumber(inputStringVector[2]) || !isNumber(inputStringVector[3])) // checking that we got numbers
                            throw MyExceptions::ParsingError("Cannot parse a non-digit character to a double or an int");
                        speed = stoi(inputStringVector[3]);
                        if( (tmpShip->getTypeName() == Ship::PB && MAX_SPEED_PATROL > speed)  ||
                                (tmpShip->getTypeName() == Ship::CR && MAX_SPEED_CRUISER > speed) ||
                                (tmpShip->getTypeName() == Ship::FR && MAX_SPEED_FREIGHTER > speed))
                            throw MyExceptions::InvalidArgument("Speed given is more than this ship can handle");

                        Model::getInstance().getVectorOfCommands().emplace_back(inputStringVector); //inserting to the vector that holds all the commands for next time update
                        break;




                    case InputCommand::POSITION:
                        if(inputStringVector[1] != "position") // checking command validation
                            throw MyExceptions::InvalidInput("Command not found");
                        if(inputStringVector.size() != 5) // exactly 5 arguments
                            throw MyExceptions::InvalidArgument("Position needs 5 arguments");
                        if(Model::getInstance().findShip(inputStringVector[0]) == Model::getInstance().getShipVec().end()) // checks if the ship already exists
                            throw MyExceptions::InvalidInput("Ship doesn't exist");
                        tmpShip = (*Model::getInstance().findShip(inputStringVector[0]));

                        inputStringVector[2].erase(inputStringVector[2].begin(),inputStringVector[3].begin() + 1); // erasing '(' from double
                        if(inputStringVector[2][inputStringVector[2].size() - 1] == ',')
                            inputStringVector[2].pop_back();
                        inputStringVector[3].pop_back(); // erasing ')'
                        if( !isNumber(inputStringVector[2]) || !isNumber(inputStringVector[3]) || !isNumber(inputStringVector[4]))
                            throw MyExceptions::ParsingError("Cannot parse a non-digit character to a double or an int");
                        if( (tmpShip->getTypeName() == Ship::PB && MAX_SPEED_PATROL > speed)  ||
                            (tmpShip->getTypeName() == Ship::CR && MAX_SPEED_CRUISER > speed) ||
                            (tmpShip->getTypeName() == Ship::FR && MAX_SPEED_FREIGHTER > speed))
                            throw MyExceptions::InvalidArgument("Speed given is more than this ship can handle");

                        Model::getInstance().getVectorOfCommands().emplace_back(inputStringVector);
                        break;





                    case InputCommand::DESTINATION:
                        if(inputStringVector[1] != "destination") // checking command validation
                            throw MyExceptions::InvalidInput("Command not found");
                        if(inputStringVector.size() != 4)
                            throw MyExceptions::InvalidArgument("Destination needs exactly 4 arguments");
                        if(Model::getInstance().findShip(inputStringVector[0]) == Model::getInstance().getShipVec().end()) // checks if the ship already exists
                            throw MyExceptions::InvalidInput("Ship doesn't exist");
                        tmpShip = (*Model::getInstance().findShip(inputStringVector[0]));

                        if(Model::getInstance().findPort(inputStringVector[2]) == Model::getInstance().getPortVec().end())
                            throw MyExceptions::InvalidArgument("Port doesn't exist");
                        if(!isNumber(inputStringVector[3]))
                            throw MyExceptions::ParsingError("Cannot parse a non-digit character to an integer");

                        if( (tmpShip->getTypeName() == Ship::PB && MAX_SPEED_PATROL > speed)  ||
                            (tmpShip->getTypeName() == Ship::CR && MAX_SPEED_CRUISER > speed) ||
                            (tmpShip->getTypeName() == Ship::FR && MAX_SPEED_FREIGHTER > speed))
                            throw MyExceptions::InvalidArgument("Speed given is more than this ship can handle");
                        Model::getInstance().getVectorOfCommands().emplace_back(inputStringVector);
                        break;




                    case InputCommand::LOAD_AT:
                        if(inputStringVector[1] != "load_at") // checking command validation
                            throw MyExceptions::InvalidInput("Command not found");
                        if(inputStringVector.size() != 3)
                            throw MyExceptions::InvalidArgument("Load at needs exactly 3 arguments");
                        if(Model::getInstance().findShip(inputStringVector[0]) == Model::getInstance().getShipVec().end()) // checks if the ship already exists
                            throw MyExceptions::InvalidInput("Ship doesn't exist");
                        if(Model::getInstance().findPort(inputStringVector[2]) == Model::getInstance().getPortVec().end())
                            throw MyExceptions::InvalidArgument("Port doesn't exist");
                        Model::getInstance().getVectorOfCommands().emplace_back(inputStringVector);
                        break;




                    case InputCommand::UNLOAD_AT:
                        if(inputStringVector[1] != "unload_at") // checking command validation
                            throw MyExceptions::InvalidInput("Command not found");
                        if(inputStringVector.size() != 4)
                            throw MyExceptions::InvalidArgument("Unload at needs exactly 4 arguments");
                        if(Model::getInstance().findShip(inputStringVector[0]) == Model::getInstance().getShipVec().end()) // checks if the ship already exists
                            throw MyExceptions::InvalidInput("Ship doesn't exist");
                        if(Model::getInstance().findPort(inputStringVector[2]) == Model::getInstance().getPortVec().end())
                            throw MyExceptions::InvalidArgument("Port doesn't exist");
                        if(!isNumber(inputStringVector[3]))
                            throw MyExceptions::ParsingError("Cannot parse a non-digit character to an integer");
                        Model::getInstance().getVectorOfCommands().emplace_back(inputStringVector);
                        break;




                    case InputCommand::DOCK_AT:
                        if(inputStringVector[1] != "dock_at") // checking command validation
                            throw MyExceptions::InvalidInput("Command not found");
                        if(inputStringVector.size() != 3)
                            throw MyExceptions::InvalidArgument("Dock at needs exactly 3 arguments");
                        if(Model::getInstance().findShip(inputStringVector[0]) == Model::getInstance().getShipVec().end()) // checks if the ship already exists
                            throw MyExceptions::InvalidInput("Ship doesn't exist");
                        if(Model::getInstance().findPort(inputStringVector[2]) == Model::getInstance().getPortVec().end())
                            throw MyExceptions::InvalidArgument("Port doesn't exist");
                        Model::getInstance().getVectorOfCommands().emplace_back(inputStringVector);
                        break;




                    case InputCommand::ATTACK:
                        if(inputStringVector[1] != "attack") // checking command validation
                            throw MyExceptions::InvalidInput("Command not found");
                        if(inputStringVector.size() != 3)
                            throw MyExceptions::InvalidArgument("Attack needs exactly 3 arguments");
                        if(Model::getInstance().findShip(inputStringVector[0]) == Model::getInstance().getShipVec().end() ||
                                Model::getInstance().findShip(inputStringVector[2]) == Model::getInstance().getShipVec().end()) // checks if the ship already exists
                            throw MyExceptions::InvalidInput("Ship doesn't exist");
                        Model::getInstance().getVectorOfCommands().emplace_back(inputStringVector);
                        break;




                    case InputCommand::REFUEL:
                        if(inputStringVector[1] != "refuel") // checking command validation
                            throw MyExceptions::InvalidInput("Command not found");
                        if(inputStringVector.size() != 2)
                            throw MyExceptions::InvalidArgument("Refuel needs exactly 2 arguments");
                        if(Model::getInstance().findShip(inputStringVector[0]) == Model::getInstance().getShipVec().end()) // checks if the ship already exists
                            throw MyExceptions::InvalidInput("Ship doesn't exist");
                        if((*(Model::getInstance().findShip(inputStringVector[0])))->getTypeName() == Ship::PB)
                            throw MyExceptions::InvalidArgument("Cannot refuek a patrol boat");
                        Model::getInstance().getVectorOfCommands().emplace_back(inputStringVector);
                        break;




                    case InputCommand::STOP:
                        if(inputStringVector[1] != "stop") // checking command validation
                            throw MyExceptions::InvalidInput("Command not found");
                        if(inputStringVector.size() != 2)
                            throw MyExceptions::InvalidArgument("Stop needs exactly 2 arguments");
                        Model::getInstance().getVectorOfCommands().emplace_back(inputStringVector);
                        break;




                    case InputCommand::EXIT:
                        inLoop = false;
                        break;
                default:
                    cout << "Command not found\n";

                } // switch
            } //while
        }//try
        catch (MyExceptions::InvalidInput& ii) {
            ii.print();
        }catch (MyExceptions::InvalidArgument& ia){
            ia.print();
        }catch(MyExceptions::ParsingError& pe){
            pe.print();
        }

    }// function run()

