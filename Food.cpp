//
// Created by Ashwin Ashok on 23/11/25.
//

#include "Food.h"

void Food::spawnFood(int boardHeight, int boardWidth) {
    int x = Food::generateRandomNumber_(1,boardWidth);
    int y = Food::generateRandomNumber_(1,boardHeight);
    foodCoords_ = {x,y};
}

int Food::generateRandomNumber_(int min_val, int max_val) const {
    // 1. Ensure the range is ordered correctly (min_val <= max_val)
    // This handles cases where a user accidentally inputs max before min.
    int lower_bound = std::min(min_val, max_val);
    int upper_bound = std::max(min_val, max_val);

    // 2. Create a Random Number Generator Engine
    // The 'std::random_device' gathers non-deterministic (truly random) entropy
    // from the operating system to seed the engine.
    std::random_device random_device;

    // The 'std::mt19937' is the Mersenne Twister engine, a high-quality
    // pseudo-random number generator, seeded by the random_device.
    std::mt19937 generator(random_device());

    // 3. Create a Distribution
    // The 'std::uniform_int_distribution' ensures that every number in the
    // specified range [lower_bound, upper_bound] has an equal chance of being selected.
    std::uniform_int_distribution<int> distribution(lower_bound, upper_bound);

    // 4. Generate and return the random number
    // We call the distribution object, passing the generator engine to it.
    return distribution(generator);
}

Point& Food::getFoodCoords_() {
    return foodCoords_;
}