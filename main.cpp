#include <iostream>

#include "GeneticAlgorithm.hpp"

int main() {
    std::vector<City> cities;

    cities.push_back(City{140, 80});
    cities.push_back(City{200, 160});
    cities.push_back(City{60, 80});
    cities.push_back(City{100, 40});
    cities.push_back(City{20, 20});
    cities.push_back(City{160, 20});
    cities.push_back(City{60, 200});
    cities.push_back(City{180, 200});
    cities.push_back(City{230, 80});
    cities.push_back(City{20, 70});
    cities.push_back(City{90, 200});
    cities.push_back(City{130, 90});
    cities.push_back(City(200, 300));
    cities.push_back(City(100, 70));
    cities.push_back(City(0, 70));
    cities.push_back(City(45, 70));

    const double improvementFactor = 0.35;
    const int iterations = 150;
    const int populationSize = 1500;
    const int numberElites = 2;
    GeneticAlgorithm::run(improvementFactor, iterations, populationSize, numberElites, cities);

    return 0;
}