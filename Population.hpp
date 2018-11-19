//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "Tour.hpp"

class Population {
private:
    std::vector<Tour> tours;

public:
    Population(int populationSize, std::vector<City> cities);

    Tour getFittest();
};


#endif //GENETICALGORITHM_POPULATION_HPP
