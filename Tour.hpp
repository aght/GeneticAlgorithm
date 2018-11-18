//
// Created by Andy Tang on 11/9/2018.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>

#include "City.hpp"

class Tour {
private:
    std::vector<City> cites;
    double fitness;
};


#endif //GENETICALGORITHM_TOUR_HPP
