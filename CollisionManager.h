//
// Created by Ashwin Ashok on 28/11/25.
//

#ifndef SNAKE_GAME_CPP_COLLISIONMANAGER_H
#define SNAKE_GAME_CPP_COLLISIONMANAGER_H

#include "Snake.h"

class CollisionManager {
public:
    CollisionManager(Snake& snake);

    bool hasCollided();

private:
    const Snake& snake_;
};
#endif //SNAKE_GAME_CPP_COLLISIONMANAGER_H
