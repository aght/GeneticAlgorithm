//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_RANDOM_HPP
#define GENETICALGORITHM_RANDOM_HPP

#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

class Random {
private:
    static std::mt19937 randomEngine;

public:
    static int randomInt(int start, int end);

    static double randomDouble(int start, int end);

    template<typename T>
    static void shuffleVector(std::vector<T> &vec, int iterations = 1);
};

/**
 * #### MUST BE DEFINED HERE ####
 *
 * Shuffles the elements in the vector
 * @tparam T type of the vector
 * @param vec vector to shuffle
 */
template<typename T>
void Random::shuffleVector(std::vector<T> &vec, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::shuffle(vec.begin(), vec.end(), randomEngine);
    }
}


#endif //GENETICALGORITHM_RANDOM_HPP
