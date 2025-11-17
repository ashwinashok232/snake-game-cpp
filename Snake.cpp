//
// Created by Ashwin Ashok on 17/11/25.
//
#include "Snake.h"

Snake::Snake(int startX, int startY) {
    body_.push_front({startX, startY});
}

void Snake::move(int dx, int dy) {
    Point newHead = { body_[0].x + dx, body_[0].y + dy };
    body_.push_front(newHead);
}