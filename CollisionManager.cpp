//
// Created by Ashwin Ashok on 28/11/25.
//

#include "CollisionManager.h"

CollisionManager::CollisionManager(Snake& snake): snake_(snake) {}

bool CollisionManager::hasCollided() {
    Point head = snake_.getHead();
    const std::deque<Point>& body = snake_.getBody();
    for (auto i = body.begin()+1; i != body.end(); ++i) {
        if (i->x == head.x && i->y == head.y) {
            return true;
        }
    }
    return false;
}