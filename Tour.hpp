//
// Created by Andy Tang on 11/9/2018.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>

#include "City.hpp"
#include "CityManager.hpp"

class Tour {
private:
    std::vector<City> cites;
    double fitness;
    double distance;
public:
    Tour();

    Tour(const std::vector<City>& cities);

    void generateRandomTour();
};


#endif //GENETICALGORITHM_TOUR_HPP
