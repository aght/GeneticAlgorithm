#include <iostream>

#include "City.hpp"
#include "GeneticAlgorithm.hpp"

int main() {
    std::vector<City> cities;

    for (int i = 0; i < 20; i++) {
        cities.push_back(City());
    }

    GeneticAlgorithm::run(1000, 50, cities);
    return 0;
}