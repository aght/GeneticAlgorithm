//
// Created by Andy on 11/18/2018.
//

#include "Tour.hpp"

Tour::Tour(const std::vector<City>& cities) {
    this->cities = cities;
    fitness = 0;
    distance = 0;
}

double Tour::getFitness() {
    if (fitness == 0) {
        fitness = 1 / getDistance();
    }

    return distance;
}

double Tour::getDistance() {
    if (distance == 0) {
        for (int i = 0; i < cities.size(); ++i) {
            City from = cities[i];
            City dest;

            if (i + 1 == cities.size()) {
                dest = cities[0];
            } else {
                dest = cities[i];
            }

            distance += from.distanceTo(dest);
        }
    }

    return distance;
}

std::vector<City>& Tour::getCities() {
    return cities;
}