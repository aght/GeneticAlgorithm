//
// Created by Andy on 11/18/2018.
//

#include "Population.hpp"

Population::Population(int populationSize, std::vector<City> cities) {
    for (int i = 0; i < populationSize; i++) {
        tours.push_back(Tour(cities));
    }
}

Tour Population::getFittest() {
    Tour fittest = tours[0];

    for (int i = 1; i < tours.size(); i++) {
        if (fittest.getDistance() > tours[i].getDistance()) {
            fittest = tours[i];
        }
    }

    return fittest;
}