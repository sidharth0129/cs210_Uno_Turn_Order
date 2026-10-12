cmake_minimum_required(VERSION 4.3)
project(cs210_pa1_boilerplate)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cs210_pa1_boilerplate
        main.cpp
        Player.h
        Stack.h
        List.cpp
        List.h
        Node.cpp
        Node.h)
