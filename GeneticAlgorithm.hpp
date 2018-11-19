//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_GENETICALGORITHN_HPP
#define GENETICALGORITHM_GENETICALGORITHN_HPP

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

    static Tour crossover(Tour p1, Tour p2);

    static Tour mutate(Tour tour);

    static Tour tournament(Population population);
};


#endif //GENETICALGORITHM_GENETICALGORITHN_HPP
