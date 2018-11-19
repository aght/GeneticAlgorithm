//
// Created by Andy on 11/18/2018.
//

#include "Tour.hpp"
Tour::Tour(int size) {
    cities.reserve(size);
}

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
        for (unsigned i = 0; i < cities.size(); ++i) {
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

City& Tour::getCity(int i) {
    return cities[i];
}

void Tour::addCity(const City &city) {
    cities.push_back(city);
}

int Tour::tourSize() {
    return cities.size();
}

void Tour::setCity(int i, const City &city) {
    cities[i] = city;
}

bool Tour::contains(const City &city) {
    return std::find(cities.begin(), cities.end(), city) != cities.end();
}

int Tour::tourCapacity() {
    return cities.capacity();
}