#include <iostream>
#include "Snake.h"

const int BOARD_WIDTH = 30;
const int BOARD_HEIGHT = 10;

void render(const Snake& snake) {
    char board[BOARD_HEIGHT][BOARD_WIDTH];

    for (int j = 0; j < BOARD_HEIGHT; j++) {
        for (int i = 0; i < BOARD_WIDTH; i++) {
            board[j][i] = ' ';
        }
    }

    board[0][0] = '+';
    for (int i = 1; i < BOARD_WIDTH-1; i++) {
        board[0][i] = '-';
    }
    board[0][BOARD_WIDTH-1] = '+';

    for (int j = 1; j < BOARD_HEIGHT-1; j++) {
        board[j][0] = '|';
        for (int i = 1; i < BOARD_WIDTH; i++) {
            board[j][i] = ' ';
        }
        board[j][BOARD_WIDTH-1] = '|';
    }

    board[BOARD_HEIGHT-1][0] = '+';
    for (int i = 1; i < BOARD_WIDTH-1; i++) {
        board[BOARD_HEIGHT-1][i] = '-';
    }
    board[BOARD_HEIGHT-1][BOARD_WIDTH-1] = '+';

    bool isHead = true;
    for (const Point& p : snake.getBody()) {
        board[p.y][p.x] = isHead ? '>' : '#';
        isHead = false;
    }

    std::system("clear");
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            std::cout << board[y][x];
        }
        std::cout << "\n";
    }
}

int main() {
    Snake snake(5,5);

    render(snake);
    return 0;
}
