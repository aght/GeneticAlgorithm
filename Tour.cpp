//
// Created by Andy on 11/18/2018.
//

#include "Tour.hpp"

Tour::Tour() : cities(), fitness(0), distance(0), size(0) {}

Tour::Tour(const std::vector<City> &cities) : cities(cities), fitness(0), distance(0), size(cities.size()) {
    std::random_shuffle(this->cities.begin(), this->cities.end());
}

Tour::Tour(const Tour &t) {
    this->cities = t.cities;
    this->fitness = t.fitness;
    this->distance = t.distance;
    this->size = t.size;
}

double Tour::getFitness() {
    if (fitness == 0) {
        fitness = 1 / getDistance();
    }

    return distance;
}

double Tour::getDistance() {
    if (distance == 0) {

        int temp = 0;

        for (int i = 0; i < cities.size(); ++i) {
            City from = cities[i];
            City dest{};

            if (i + 1 == cities.size()) {
                dest = cities[0];
            } else {
                dest = cities[i + 1];
            }

            distance += from.distanceTo(dest);
        }
    }

    return distance;
}

City Tour::getCity(int index) {
    return cities[index];
}

void Tour::setCity(int index, const City &city) {
    cities[index] = city;
}

void Tour::addCity(const City &city) {
    cities.push_back(city);
    ++size;
}

int Tour::tourSize() {
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