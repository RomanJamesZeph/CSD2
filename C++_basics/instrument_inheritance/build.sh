#! /bin/bash

g++ -c main.cpp
g++ -c instrument.cpp
g++ -c string.cpp
g++ -c wind.cpp
g++ -c percussion.cpp
g++ -o instrument main.o instrument.o string.o wind.o percussion.o