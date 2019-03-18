cmake_minimum_required(VERSION 3.13)
project(Taki)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Taki
        Card.cpp
        Card.h
        Game.cpp
        Game.h
        main.cpp
        Player.cpp
        Player.h)