cmake_minimum_required(VERSION 4.0)
project(ASCIIAquarium C)

set(CMAKE_C_STANDARD 11)

add_executable(ASCIIAquarium main.c
        utils.h
        utils.c
        fish.c
        fish.h
        aquarium.c
        aquarium.h)
