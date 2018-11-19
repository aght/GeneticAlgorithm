//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include "Population.hpp"

class GeneticAlgorithm {
private:
    static constexpr double MUTATION_RATE = 0.015;
    static constexpr double POOL_SIZE = 5;
    static constexpr int NUM_ELITES = 1;

public:
    static void run(int iterations, int populationSize, std::vector<City> cities);

private:
    static Population evolve(Population& population);

    static Tour crossover(const Tour& p1, const Tour& p2);

    static Tour mutate(Tour tour);

    static Tour tournament(const Population& population);
};


#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
