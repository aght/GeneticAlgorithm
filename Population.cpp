//
// Created by Andy on 11/18/2018.
//

#include "Population.hpp"

Population::Population() : size(0) {}

Population::Population(int populationSize, const std::vector<City> cities) : size(populationSize) {
    for (int i = 0; i < populationSize; ++i) {
        Tour t{cities};
        tours.push_back(t);
    }
}

Population::Population(const Population& population) {
    this->size = population.size;
    this->tours = population.tours;
}

Tour Population::getTour(int index) const {
    return tours[index];
}

void Population::addTour(const Tour &tour) {
    tours.push_back(tour);
    ++size;
}

void Population::setTour(int index, const Tour &tour) {
    tours[index] = tour;
}

Tour Population::getFittest() {
    Tour fittest = tours[0];

    for (int i = 0; i < tours.size(); ++i) {
        if (fittest.getFitness() > tours[i].getFitness()) {
            fittest = tours[i];
        }
    }

    return fittest;
}

int Population::populationSize() const {
    return size;
}