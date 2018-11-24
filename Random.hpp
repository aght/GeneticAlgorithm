//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_RANDOM_HPP
#define GENETICALGORITHM_RANDOM_HPP

#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

/**
 * Class containing functions for randomization
 */
class Random {
private:

    /**
     * Random number generator
     */
    static std::mt19937 randomEngine;

public:

    /**
     * Generates a random integer between two ranges (inclusive)
     *
     * @param start lower bound
     * @param end upper bound
     * @return random integer between lower and upper bound (inclusive)
     */
    static int randomInt(int start, int end);

    /**
     * Generates a random double between two ranges (inclusive)
     *
     * @param start lower bound
     * @param end upper bound
     * @return random double between lower and upper bound (inclusive)
     */
    static double randomDouble(int start, int end);

    /**
    * Shuffles the elements in the vector
    *
    * @tparam T type of the vector
    * @param vec vector to shuffle
    */
    template<typename T>
    static void shuffleVector(std::vector<T> &vec, int iterations = 1);
};

// Must be defined inside header in order to allow for any type of vector
template<typename T>
void Random::shuffleVector(std::vector<T> &vec, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::shuffle(vec.begin(), vec.end(), randomEngine);
    }
}


#endif //GENETICALGORITHM_RANDOM_HPP
