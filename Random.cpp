//
// Created by Andy on 11/18/2018.
//

#include "Random.hpp"

std::mt19937 Random::randomEngine(std::chrono::system_clock::now().time_since_epoch().count());

int Random::randomInt(int start, int end) {
    std::uniform_int_distribution<int> distribution(start, end);
    return distribution(randomEngine);
}