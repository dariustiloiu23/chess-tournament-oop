cmake_minimum_required(VERSION 4.1)
project(proiectul3poo)

set(CMAKE_CXX_STANDARD 17)

add_executable(proiectul3poo main.cpp
        Exceptii.cpp
        Exceptii.h
        IObject.cpp
        IObject.h
        Patterns.cpp
        Patterns.h
        Domeniu.cpp
        Domeniu.h
        Generic.cpp
        Generic.h)
