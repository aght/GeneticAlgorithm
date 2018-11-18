//
// Created by Andy Tang on 11/9/2018.
//

#include "Tour.hpp"

Tour::Tour() : fitness(0), distance(0), cites() {}

Tour::Tour(const std::vector<City> &cities) : fitness(0), distance(0), cites(cities) {}

void Tour::generateRandomTour() {
}