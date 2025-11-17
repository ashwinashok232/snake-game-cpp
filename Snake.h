//
// Created by Ashwin Ashok on 17/11/25.
//

#ifndef SNAKE_GAME_CPP_SNAKE_H
#define SNAKE_GAME_CPP_SNAKE_H

#include <deque>

struct Point {
    int x;
    int y;
};

class Snake {
public:
    Snake(int startX, int startY);

    void move(int dx, int dy);

private:
    std::deque<Point> body_;
};

#endif //SNAKE_GAME_CPP_SNAKE_H
