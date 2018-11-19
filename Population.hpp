//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "Tour.hpp"

class Population {
private:
    std::vector<Tour> tours;
    int populationSize;

public:
    Population(int populationSize);

    Population(int populationSize, std::vector<City> cities);

    Tour getFittest();

    int getPopulationSize() const;

    Tour& getTour(int i);

    void setTour(int i, const Tour& tour);
};


#endif //GENETICALGORITHM_POPULATION_HPP
