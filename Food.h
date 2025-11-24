//
// Created by Ashwin Ashok on 23/11/25.
//

#ifndef SNAKE_GAME_CPP_FOOD_H
#define SNAKE_GAME_CPP_FOOD_H

#include "Snake.h"
#include <iostream>
#import <random>
#include <chrono>
#include <algorithm>

class Food {
public:
    void spawnFood(int boardHeight, int boardWidth);
    Point& getFoodCoords_();
    void setIsEaten(bool isEaten);
    void deleteFood(Point curPosition);


private:
    bool isEaten_ = false;
    Point foodCoords_ = {-1, -1};
    int generateRandomNumber_(int minVal, int maxVal) const;
};

#endif //SNAKE_GAME_CPP_FOOD_H
