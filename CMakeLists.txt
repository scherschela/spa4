cmake_minimum_required(VERSION 3.30)
project(spa4)

set(CMAKE_CXX_STANDARD 20)

add_executable(spa4 src/main.cpp
        src/Map.cpp
        src/Map.h
        src/Room.h
        src/Player.h
        src/Cat.h
        src/Game.h
        src/Room.cpp
        src/Player.cpp
        src/Game.cpp
        src/Cat.cpp)
