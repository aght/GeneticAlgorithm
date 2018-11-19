//
// Created by Andy on 11/18/2018.
//

#include "Population.hpp"

Population::Population(const std::vector<City>& cities) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        tours.push_back(Tour::generateRandomTour(cities));
    }
}

Tour Population::getFittest() {
    Tour fittest = tours[0];
    for (int i = 0; i < tours.size(); i++) {
        if (tours[i].getFitness() < fittest.getFitness()) {
            fittest = tours[i];
        }
    }

    return fittest;
}