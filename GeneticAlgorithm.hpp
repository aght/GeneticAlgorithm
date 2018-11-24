//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include <iostream>

#include "Population.hpp"

/**
 * Genetic Algorithm functions
 */
class GeneticAlgorithm {
private:

    /**
     * Mutation rate, should be low (< 15%)
     */
    static constexpr double MUTATION_RATE = 0.05;

    /**
     * Pool size for picking parents for crossover
     */
    static constexpr double POOL_SIZE = 5;

public:

    /**
     * Runs the algorithm
     *
     * @param factor target percentage to improve by
     * @param iterations number of iterations to run the algorithm
     * @param populationSize size of the population of Tours, larger populations have a higher change to gain better answer
     * @param numElites number of elites
     * @param cities cites to run the algorithm on
     */
    static void run(double factor, int iterations, int populationSize, int numElites, std::vector<City> cities);

private:

    /**
     * Evolve the population
     *
     * @param population population to evolve
     * @param numElites number of elites that should be kept
     * @return evolved population
     */
    static Population evolve(Population& population, int numElites);

    /**
     * Create a new tour based on two other tours
     *
     * @param p1 tour 1
     * @param p2 tour 2
     * @return child tour
     */
    static Tour crossover(const Tour& p1, const Tour& p2);

    /**
     * Randomly swaps cities in a tour based on a mutation rate
     *
     * @param tour
     * @return
     */
    static Tour mutate(Tour tour);

    /**
     * Select a number of tours from a population and returns the fittest
     *
     * @param population population to select from
     * @return fittest tour of the selected tours
     */
    static Tour selection(const Population &population);

    /**
     * Gets N number of elites from a population
     *
     * @param n number of elites to get
     * @param population population to select from
     * @return population containing N number of elites
     */
    static Population getNElites(int n, Population population);
};


#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
