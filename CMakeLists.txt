cmake_minimum_required(VERSION 3.9)
project(Exercise3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Exercise3 main.cpp Controller.cpp Controller.h Cruiser.cpp Cruiser.h Freighter.cpp Freighter.h Geometry.cpp Geometry.h Model.cpp Model.h PatrolBoat.cpp PatrolBoat.h Port.cpp Port.h Ship.cpp Ship.h TrackBase.cpp TrackBase.h View.cpp View.h AbstractFactory.cpp AbstractFactory.h ShipFactory.cpp ShipFactory.h)