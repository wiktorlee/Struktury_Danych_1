cmake_minimum_required(VERSION 3.30)
project(Projekt1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt1
        main.cpp
        TablicaDynamiczna.cpp
        TablicaDynamiczna.hpp
        TabliceGenerator.cpp
        TabliceGenerator.hpp
        ListaJednokierunkowa.cpp
        ListaJednokierunkowa.hpp
        DoublyLinkedList.cpp
        DoublyLinkedList.h
        Badanie.cpp
        Badanie.hpp
)
