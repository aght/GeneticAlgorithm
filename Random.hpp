//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_RANDOM_HPP
#define GENETICALGORITHM_RANDOM_HPP

#include <chrono>
#include <random>

class Random {
private:
    static std::mt19937 randomEngine;
public:
    static int randomInt(int start, int end);
};


#endif //GENETICALGORITHM_RANDOM_HPP
