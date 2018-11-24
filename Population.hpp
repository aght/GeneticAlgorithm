//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "Tour.hpp"

/**
 * Represents a population of tours
 */
class Population {
private:

    /**
     * Collection of tours
     */
    std::vector<Tour> tours;

    /**
     * Size of the population
     */
    int size;

public:

    /**
     * Default constructor
     */
    Population();

    /**
     * Constructs a population from a list of cities
     *
     * @param populationSize size of the population
     * @param cities cites to construct from
     */
    Population(int populationSize, const std::vector<City> cities);

    /**
     * Copy constructor
     *
     * @param population population to copy
     */
    Population(const Population& population);

    /**
     * Gets a specific tour by index
     *
     * @param index index
     * @return tour at the index
     */
    Tour getTour(int index) const;

    /**
     * Adds a tour to this population
     *
     * @param tour tour to add
     */
    void addTour(const Tour& tour);

    /**
     * Sets a tour at an index
     *
     * @param index index
     * @param tour tour to set
     */
    void setTour(int index, const Tour& tour);

    /**
     * Gets the fittest tour in this population
     *
     * @return fittest tour
     */
    Tour getFittest();

    /**
     * Gets the size of this population
     *
     * @return size
     */
    int populationSize() const;

    /**
     * Equals operator
     *
     * @param p1 population 1
     * @param p2 population 2
     * @return true if the address of both object are the same
     */
    friend bool operator==(const Population &p1, const Population &p2);
};

inline bool operator==(const Population &p1, const Population &p2) {
    return &p1 == &p2;
}


#endif //GENETICALGORITHM_POPULATION_HPP
