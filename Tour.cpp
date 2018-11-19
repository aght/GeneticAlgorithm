//
// Created by Andy Tang on 11/9/2018.
//

#include <chrono>
#include "Tour.hpp"

std::mt19937 Tour::randomEngine(std::chrono::system_clock::now().time_since_epoch().count());

Tour::Tour(const std::vector<City> &cities) : cities(cities), fitness(0), distance(0) {}

Tour Tour::generateRandomTour(const std::vector<City> &cities) {
    Tour tour{cities};

    std::shuffle(std::begin(tour.cities), std::end(tour.cities), randomEngine);

    return tour;
}

double Tour::getFitness() {
    if (fitness == 0) {
        fitness = 1 / getDistance();
    }

    return fitness;
}

double Tour::getDistance() {
    if (distance == 0) {

        for (unsigned i = 0; i < cities.size(); ++i) {
            City fromCity = cities[i];
            City destCity{};

            if (i + 1 >= cities.size()) {
                destCity = cities[0];
            } else {
                destCity = cities[i + 1];
            }

            distance += fromCity.distanceTo(destCity);
        }
    }

    return distance;
}