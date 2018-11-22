//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "Tour.hpp"

class Population {
private:
    std::vector<Tour> tours;
    int size;

public:
    Population();

    Population(int populationSize, const std::vector<City> cities);

    Population(const Population& population);

    Tour getTour(int index) const;

    void addTour(const Tour& tour);

    void setTour(int index, const Tour& tour);

    Tour getFittest();

    int populationSize() const;

    friend bool operator==(const Population &p1, const Population &p2);
};

inline bool operator==(const Population &p1, const Population &p2) {
    return &p1 == &p2;
}


#endif //GENETICALGORITHM_POPULATION_HPP
