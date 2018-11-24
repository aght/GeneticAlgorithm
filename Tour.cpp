//
// Created by Andy on 11/18/2018.
//

#include "Tour.hpp"

Tour::Tour() : cities(), fitness(0), distance(0), size(0) {}

Tour::Tour(const std::vector<City> &cities) : cities(cities), fitness(0), distance(0), size(cities.size()) {
    Random::shuffleVector(this->cities, SHUFFLE_ITERATIONS);
}

Tour::Tour(const Tour &t) {
    this->cities = t.cities;
    this->fitness = t.fitness;
    this->distance = t.distance;
    this->size = t.size;
}

double Tour::getFitness() {
    if (fitness == 0) {
        fitness = (1 / getDistance()) * FITNESS_SCALAR;
    }

    return fitness;
}

double Tour::getDistance() {
    if (distance == 0) {

        for (int i = 0; i < static_cast<int>(cities.size()); ++i) {
            City from = cities[i];
            City dest{};

            if (i + 1 == static_cast<int>(cities.size())) {
                dest = cities[0];
            } else {
                dest = cities[i + 1];
            }

            distance += from.distanceTo(dest);
        }
    }

    return distance;
}

City Tour::getCity(int index) const {
    return cities[index];
}

void Tour::setCity(int index, const City &city) {
    cities[index] = city;
}

void Tour::addCity(const City &city) {
    cities.push_back(city);
    ++size;
}

int Tour::tourSize() const {
    return size;
}

bool Tour::contains(const City &city) {
    return std::find(cities.begin(), cities.end(), city) != cities.end();
}

Tour &Tour::operator=(Tour other) {
    std::swap(this->cities, other.cities);
    std::swap(this->fitness, other.fitness);
    std::swap(this->distance, other.distance);

    return *this;
}