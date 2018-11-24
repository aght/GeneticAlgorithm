//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#include "City.hpp"
#include "Random.hpp"

/**
 * Represents a tour
 */
class Tour {
private:

    /**
     * Number of iterations to shuffle the cities in the tour
     */
    static constexpr int SHUFFLE_ITERATIONS = 64;

    /**
     * Scalar to multiply the fitness of the tour by
     */
    static constexpr int FITNESS_SCALAR = 1000;

    /**
     * Collection of cities in the tour
     */
    std::vector<City> cities;

    /**
     * Fitness of this tour
     */
    double fitness;

    /**
     * Total distance of this tour
     */
    double distance;

    /**
     * Number of cities in this tour
     */
    int size;

public:

    /**
     * Default constructor
     */
    Tour();

    /**
     * Constructs a tour from a list of cities
     *
     * @param cities cities to construct from
     */
    Tour(const std::vector<City> &cities);

    /**
     * Copy constructor
     *
     * @param t tour to copy
     */
    Tour(const Tour &t);

    /**
     * Calulates the fitness of this tour
     *
     * @return fitness
     */
    double getFitness();

    /**
     * Calculates the total distance of this tour
     *
     * @return total distance
     */
    double getDistance();

    /**
     * Gets a city at an index
     *
     * @param index index
     * @return city at index
     */
    City getCity(int index) const;

    /**
     * Sets a city at an index
     *
     * @param index index
     * @param city city to set with
     */
    void setCity(int index, const City &city);

    /**
     * Adds a city to the tour
     *
     * @param city city to add
     */
    void addCity(const City &city);

    /**
     * Returns the size of tour
     *
     * @return size
     */
    int tourSize() const;

    /**
     * Checks if this tour contains a city
     *
     * @param city city to look for
     * @return true if the city is found
     */
    bool contains(const City &city);

    /**
     * Assignment operator
     *
     * @param other Tour to copy
     * @return this
     */
    Tour &operator=(Tour other);

    /**
     * Insertion operator
     *
     * @param os ostream
     * @param tour tour
     * @return ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const Tour& tour);

    /**
     * Equals operator
     *
     * @param t1 tour 1
     * @param t2 tour 2
     * @return true if both equal
     */
    friend bool operator==(const Tour &t1, const Tour &t2);
};

inline std::ostream& operator<<(std::ostream& os, const Tour& tour) {
    for (City city : tour.cities) {
        os << city << std::endl;
    }

    return os;
}

inline bool operator==(const Tour &t1, const Tour &t2){
    return &t1 == &t2;
}


#endif //GENETICALGORITHM_TOUR_HPP
