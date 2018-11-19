//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include <vector>

#include "Tour.hpp"

class Population {
private:
    static constexpr int POPULATION_SIZE = 32;

    std::vector<Tour> tours;

public:
    Population(const std::vector<City>& cities);

    Tour getFittest();
};


#endif //GENETICALGORITHM_POPULATION_HPP
