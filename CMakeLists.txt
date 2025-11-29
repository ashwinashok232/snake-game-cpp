cmake_minimum_required(VERSION 3.31)
project(snake_game_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(snake_game_cpp main.cpp
        Snake.h
        Snake.cpp
        Food.h
        Food.cpp
        CollisionManager.h
        CollisionManager.cpp)
