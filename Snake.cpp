//
// Created by Ashwin Ashok on 17/11/25.
//
#include "Snake.h"

Snake::Snake(int startX, int startY) {
    body_.push_front({startX, startY});
}

void Snake::move(int dx, int dy) {
    Point head = body_.front();
    Point newHead = { head.x + dx, head.y + dy };
//    std::cout << head.x << " " << head.y << " " << dx << " " << dy << "\n";
    body_.push_front(newHead);

    if (!growPending_) {
        body_.pop_back();
    }
    else {
        growPending_ = false;
    }
}

const std::deque<Point>& Snake::getBody() const {
    return body_;
}

Point Snake::getHead() const {
    return body_.front();   // same as body_[0]
}

void Snake::growOnNextMove() {
    growPending_ = true;
}