//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>

#include "City.hpp"

class Tour {
private:
    std::vector<City> cities;
    double fitness;
    double distance;
public:
    Tour(const std::vector<City>& cities);

    double getFitness();
    double getDistance();

    std::vector<City>& getCities();
};


#endif //GENETICALGORITHM_TOUR_HPP
