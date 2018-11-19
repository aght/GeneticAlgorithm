//
// Created by Andy Tang on 11/9/2018.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include <random>
#include <algorithm>
#include <ostream>

#include "City.hpp"

class Tour {
private:
    static std::mt19937 randomEngine;

    std::vector<City> cities;
    double fitness;
    double distance;
public:
    Tour() = default;

    Tour(const std::vector<City> &cities);

    std::vector<City> getCities() const;

    double getFitness();

    double getDistance();

    friend std::ostream &operator<<(std::ostream &os, const Tour &tour);

public:
    static Tour generateRandomTour(const std::vector<City> &cities);
};

inline std::ostream &operator<<(std::ostream &os, const Tour &tour) {
    for (City city : tour.cities) {
        os << city << std::endl;
    }

    return os;
}

#endif //GENETICALGORITHM_TOUR_HPP
