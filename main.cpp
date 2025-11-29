#include <iostream>
#include "Snake.h"
#include "Food.h"
#include "CollisionManager.h"
#include <vector>

const int BOARD_HEIGHT = 10;
const int BOARD_SHAPE_FACTOR = 3;
const int BOARD_WIDTH = BOARD_SHAPE_FACTOR * BOARD_HEIGHT;

void render(const std::deque<Point>& snakeBody, const Point& foodCoordinate) {
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
    for (const Point& p : snakeBody) {
        board[p.y][p.x] = isHead ? '+' : '#';
        isHead = false;
    }

    board[foodCoordinate.y][foodCoordinate.x] =  'o';

    std::system("clear");
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            std::cout << board[y][x];
        }
        std::cout << "\n";
    }
}

std::vector<int> convertInputToDirection(const int directionNum) {
    switch (directionNum) {
        case 1:
            return {0,-1};
        case 2:
            return {1,0};
        case 3:
            return {0,1};
        case 4:
            return {-1,0};
        default:
            throw std::invalid_argument("Input must be an integer between 1 and 4");
    }
}

void showMovementBoard() {
    std::cout << R"(

Enter a direction to travel

      1
      ^
4 <       > 2
      v
      3

"Enter direction to travel [1-4]";
    )";
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    Snake snake(5,5);
    Food food;
    food.spawnFood(BOARD_HEIGHT, BOARD_WIDTH);

    render(snake.getBody(), food.getFoodCoords_());
    showMovementBoard();

    while (true) {
        int directionNum;
        std::cin >> directionNum;
        clearScreen();
        std::vector dir = convertInputToDirection(directionNum);
        snake.move(dir[0], dir[1]);
        Point curHead = snake.getHead();

        Point curSnakeCoord = snake.getHead();
        Point curFoodCoord = food.getFoodCoords_();

        if (curSnakeCoord.x == curFoodCoord.x && curSnakeCoord.y == curFoodCoord.y) {
            food.spawnFood(BOARD_HEIGHT, BOARD_WIDTH);
            snake.growOnNextMove();
        }

        render(snake.getBody(), food.getFoodCoords_());
        CollisionManager col(snake);
        if (col.hasCollided()) {
            std::cout << "GAME OVER";
        }
        else {
            showMovementBoard();
        }
    }
    return 0;
}
