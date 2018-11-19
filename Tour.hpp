//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include <algorithm>

#include "City.hpp"

class Tour {
private:
    std::vector<City> cities;
    double fitness;
    double distance;
public:
    Tour(int size);

    Tour(const std::vector<City>& cities);

    double getFitness();
    double getDistance();

    City& getCity(int i);

    void addCity(const City& city);

    void setCity(int i, const City& city);

    int tourSize();

    bool contains(const City& city);

    int tourCapacity();
};


#endif //GENETICALGORITHM_TOUR_HPP
